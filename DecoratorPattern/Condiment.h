#pragma once
#include "Coffee.h"

// we use there condimentdecorator because 
// we want to add condiments to our beverage 
class SteamedMilk : public CondimentDecorator {
private:
	Beverage* beverage;
public:
	SteamedMilk(Beverage* beverage) { this->beverage = beverage; }
	string getDescription() {
		return beverage->getDescription() + ", Steamed Milk";
	}
	double cost() {
		return .10 + beverage->cost();
	}
};

class Mocha : public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Mocha(Beverage* beverage) { this->beverage = beverage; }
	string getDescription() {
		return beverage->getDescription() + ", Mocha";
	}
	double cost() {
		return .20 + beverage->cost();
	}
};

class Soy : public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Soy(Beverage* beverage) { this->beverage = beverage; }
	string getDescription() {
		return beverage->getDescription() + ", Soy";
	}
	double cost() {
		return .15 + beverage->cost();
	}
};

class Whip : public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Whip(Beverage* beverage) { this->beverage = beverage; }
	string getDescription() {
		return beverage->getDescription() + ", Whip";
	}
	double cost() {
		return .10 + beverage->cost();
	}
};

