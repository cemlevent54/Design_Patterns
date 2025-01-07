#pragma once
#include <iostream>
using namespace std;
#include <string>

class Observer {
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject {
public:
	virtual void registerObserver(Observer*) = 0;
	virtual void removeObserver(Observer*) = 0;
	virtual void notifyObservers() const = 0;
};

class DisplayElement {
public:
	virtual void display() = 0;
};

