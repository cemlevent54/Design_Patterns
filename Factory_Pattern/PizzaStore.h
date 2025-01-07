#pragma once
#include "SimplePizzaFactory.h"

class PizzaStore {
public:
    PizzaStore(SimplePizzaFactory* factory) : factory(factory) {}

    std::unique_ptr<Pizza> orderPizza(const std::string& type) {
        auto pizza = factory->createPizza(type);

        if (pizza) {
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }

        return pizza;
    }

private:
    SimplePizzaFactory* factory;
};