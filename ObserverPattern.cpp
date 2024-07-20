#include <iostream>
#include <vector>
// While detaching swap elemnt with last 
// Make small function inline 
// Loop Unrolling - reserve // avoid multiple reallocation and can improve performance 
// noexcept=0 -> Marking the update, attach, detach and notify methods as noexcept
//indicates that thse function are not expected to throw exceptions 
// Forward declaration of Subject class
class Subject;

#include <algorithm>

// Observer interface
class Observer {
public:
    virtual void update() noexcept = 0;
};

// Subject class
class Subject {
private:
    std::vector<Observer*> observers;

public:
    Subject() {
        observers.reserve(10); // Reserve capacity if you have an estimate
    }

    inline void attach(Observer* observer) noexcept {
        observers.push_back(observer);
    }

    inline void detach(Observer* observer) noexcept {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            std::iter_swap(it, observers.end() - 1);
            observers.pop_back();
        }
    }

    inline void notify() noexcept {
        for (auto observer : observers) {
            observer->update();
        }
    }
};

// Concrete Observer classes
class ConcreteObserverA : public Observer {
public:
    void update() override {
        std::cout << "ConcreteObserverA received an update." << std::endl;
        // Perform specific update logic for ConcreteObserverA
    }
};

class ConcreteObserverB : public Observer {
public:
    void update() override {
        std::cout << "ConcreteObserverB received an update." << std::endl;
        // Perform specific update logic for ConcreteObserverB
    }
};

int main() {
    Subject subject;

    ConcreteObserverA observerA;
    ConcreteObserverB observerB;

    subject.attach(&observerA);
    subject.attach(&observerB);

    // Trigger an update
    subject.notify();

    subject.detach(&observerA);

    // Trigger another update
    subject.notify();

    return 0;
}