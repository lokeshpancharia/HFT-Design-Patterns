#include <iostream>
#include <variant>


// std::variant - to hold either productA/B without dynamic memory allocation 
// Abstract product class
class Product {
public:
    virtual ~Product() = default;
    virtual void operation() = 0;
};

// Concrete product classes
class ConcreteProductA : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProductA operation\n";
    }
};

class ConcreteProductB : public Product {
public:
    void operation() override {
        std::cout << "ConcreteProductB operation\n";
    }
};

// Factory class
class Factory {
public:
    std::variant<ConcreteProductA, ConcreteProductB> createProduct(int type) {
        switch (type) {
            case 1:
                return ConcreteProductA();
            case 2:
                return ConcreteProductB();
            default:
                throw std::invalid_argument("Invalid product type");
        }
    }
};

int main() {
    Factory factory;
    auto productA = factory.createProduct(1);
    std::visit([](auto& product) { product.operation(); }, productA);

    auto productB = factory.createProduct(2);
    std::visit([](auto& product) { product.operation(); }, productB);

    return 0;
}