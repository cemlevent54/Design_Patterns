#pragma once
#include <string>
using namespace std;
#include <iostream>
class Beverage {
protected:
	string description;
public:
	Beverage() { description = "Unknown Beverage"; }
	virtual string getDescription() { return description; }
	virtual double cost() = 0;
};


// it applies open-closed principle by allowing classes to be extended 
// without modifying them. 
class CondimentDecorator : public Beverage {
public:
	virtual string getDescription() = 0;
};

class Espresso : public Beverage {
public:
	Espresso() { description = "Espresso"; }
	double cost() { return 1.99; };
};

class HouseBlend : public Beverage {
public:
	HouseBlend() { description = "House Blend Coffee"; }
	double cost() { return 0.89; };
};

class DarkRoast : public Beverage {
public:
	DarkRoast() { description = "Dark Roast Coffee"; }
	double cost() { return 0.99; };
};

class Decaf : public Beverage {
public:
	Decaf() { description = "Decaf Coffee"; }
	double cost() { return 1.05; };
};


