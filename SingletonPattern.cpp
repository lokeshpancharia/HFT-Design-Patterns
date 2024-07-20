class Singleton {
private:
    static Singleton* instance;
    
    // Private constructor to prevent instantiation
    Singleton() {}
    
    // Declare copy constructor and assignment operator as private
    Singleton(const Singleton&) {}
    Singleton& operator=(const Singleton&) {}
    
public:
    // Static method to get the instance of the Singleton class
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    // Other member functions of the Singleton class
    // ...
};

// Initializing the static instance variable
Singleton* Singleton::instance = nullptr;