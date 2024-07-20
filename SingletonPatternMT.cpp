#include <memory>
#include <mutex>

class Singleton {
private:
    static std::unique_ptr<Singleton> instance;
    static std::once_flag initInstanceFlag;

    // Private constructor to prevent instantiation
    Singleton() {}

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method to get the instance of the Singleton class
    static Singleton* getInstance() {
        std::call_once(initInstanceFlag, []() {
            instance.reset(new Singleton());
        });
        return instance.get();
    }

    // Static method to destroy the instance of the Singleton class
    static void destroyInstance() {
        instance.reset(nullptr);
    }

    // Other member functions of the Singleton class
    // ...
};

// Initialize the static instance variable
std::unique_ptr<Singleton> Singleton::instance;
std::once_flag Singleton::initInstanceFlag;
