#pragma once
#include <iostream>
using namespace std;
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck {
protected: // should normally be private, but protected to understand pattern
	QuackBehavior* quackBehavior;
	FlyBehavior* flyBehavior;
public:
	Duck() {	}
	void performQuack() {
		quackBehavior->quack();
}
	//virtual ~Duck() = 0;
	virtual void display() = 0;
	void performFly() {
		flyBehavior->fly();
	}
	void swim() {
		cout << "All ducks float, even decoys!" << endl;
	}

	void setFlyBehavior(FlyBehavior* _flyBehavior) {
		flyBehavior = _flyBehavior;
	}
	void setQuackBehavior(QuackBehavior* _quackBehavior) {
		quackBehavior = _quackBehavior;
	}
};

class MallardDuck : public Duck {
public:
	MallardDuck() {
		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings(); // polimorfizm
}
	void display() {
		cout << "I'm a real Mallard duck" << endl;
}
};

class ModelDuck :public Duck {
public:
	ModelDuck() {
		quackBehavior = new Quack();
		flyBehavior = new FlyNoWay();
	}
	void display() {
		cout << "I'm a model duck" << endl;
	}
};