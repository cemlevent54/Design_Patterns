#pragma once
#include <memory>
#include "Pizza.h"

class SimplePizzaFactory {
public:
    std::unique_ptr<Pizza> createPizza(const std::string& type) {
        if (type == "cheese") {
            return std::make_unique<CheesePizza>();
        }
        else if (type == "veggie") {
            return std::make_unique<VeggiePizza>();
        }
        else {
            return nullptr;
        }
    }
};