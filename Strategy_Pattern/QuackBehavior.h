#pragma once
#include <iostream>
using namespace std;
#include <string>

class QuackBehavior {
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
	void quack() {
		cout << "Quack" << endl;
}
};

class MuteQuack : public QuackBehavior {
public:
	void quack() {
		cout << "Silence" << endl;
}
};

class Squeak : public QuackBehavior {
public:
	void quack() {
		cout << "Squeak" << endl;
}
};