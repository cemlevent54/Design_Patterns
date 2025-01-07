#pragma once
#include<iostream>
#include<string>
using namespace std;

class Pizza {
public:
    virtual void prepare() {
        std::cout << "Preparing " << name << std::endl;
    }
    virtual void bake() {
        std::cout << "Baking " << name << std::endl;
    }
    virtual void cut() {
        std::cout << "Cutting " << name << std::endl;
    }
    virtual void box() {
        std::cout << "Boxing " << name << std::endl;
    }
    virtual ~Pizza() = default;

protected:
    std::string name;
};

class CheesePizza : public Pizza {
public:
    CheesePizza() {
        name = "Cheese Pizza";
    }
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza() {
        name = "Veggie Pizza";
    }
};