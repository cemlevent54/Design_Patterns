// Factory_Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Simple Factory Pattern
// it violates the open-closed principle
// but it is a good starting point for understanding the factory pattern
// for bigger projects, we should use the factory method pattern or abstract factory pattern
#include <iostream>
using namespace std;
#include "SimplePizzaFactory.h"
#include "PizzaStore.h"

int main()
{
    SimplePizzaFactory factory; // creating pizza is in here, not in Pizzastore
    PizzaStore store(&factory);

    std::cout << "Choose Pizza Type (cheese, veggie): ";
    std::string type;
    std::cin >> type;

    auto pizza = store.orderPizza(type);
    if (!pizza) {
        std::cout << "Geçersiz pizza türü seçildi!" << std::endl;
    }

    return 0;
}

