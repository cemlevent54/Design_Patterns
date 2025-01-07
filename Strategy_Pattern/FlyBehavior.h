#pragma once
#include<iostream>
using namespace std;
#include<string>

class FlyBehavior {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
	void fly() {
		cout << "I'm flying with wings." << endl;
	}
};

class FlyNoWay : public FlyBehavior {
public:
	void fly() {
		cout << "I can't fly anyway." << endl;
}
};

class FlyRocketPowered :public FlyBehavior {
public:
	void fly() {
		cout << "I'm flying with a rocket!" << endl;
	}
};