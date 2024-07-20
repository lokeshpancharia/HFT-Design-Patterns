#include <iostream>

// Base strategy interface
class Strategy {
public:
    virtual int execute(int a, int b) = 0;
};

// Concrete strategy implementations
class AddStrategy : public Strategy {
public:
    int execute(int a, int b) override {
        return a + b;
    }
};

class SubtractStrategy : public Strategy {
public:
    int execute(int a, int b) override {
        return a - b;
    }
};

class MultiplyStrategy : public Strategy {
public:
    int execute(int a, int b) override {
        return a * b;
    }
};

// Context class that uses the strategy
class Context {
private:
    Strategy* strategy;

public:
    constexpr Context(Strategy* strategy) : strategy(strategy) {}

    constexpr int executeStrategy(int a, int b) {
        return strategy->execute(a, b);
    }
};

int main() {
    // Create strategies
    constexpr AddStrategy addStrategy;
    constexpr SubtractStrategy subtractStrategy;
    constexpr MultiplyStrategy multiplyStrategy;

    // Create context with the desired strategy
    constexpr Context context(&addStrategy);

    // Execute the strategy
    constexpr int result = context.executeStrategy(5, 3);
    std::cout << "Result: " << result << std::endl;

    return 0;
}