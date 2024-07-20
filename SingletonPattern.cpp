#include <memory>
#include <mutex>

class Singleton {
private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method to get the instance of the Singleton class
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    // Other member functions of the Singleton class
    // ...
};