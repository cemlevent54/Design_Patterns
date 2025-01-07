#pragma once
#include <iostream>
#include <string>
using namespace std;

class Device {
    string name;
public:
    // constructor - destructor
    Device(string name) { this->name = name; }
	virtual ~Device() = default; // Added destructor for base class
    // getter - setter
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    // methods
    virtual void on() = 0;
    virtual void off() = 0;
};

class Light : public Device {
    public:
	Light(string name) : Device(name) {}
	void on() override {
		cout << getName() << " is ON" << endl;
	}
	void off() override {
		cout << getName() << " is OFF" << endl;
	}
};

class CeilingFan : public Device {
	mutable int level;
public:
	static const int HIGH = 3;
	static const int MEDIUM = 2;
	static const int LOW = 1;
	static const int OFF = 0;

	CeilingFan(string name) : level(LOW), Device(name) {}
	void on() override {
		cout << getName() << " is ON" << endl;
	}
	void off() override {
		level = OFF;
		cout << getName() << " is OFF" << endl;
	}
	int getSpeed() const { return level; }
	void high() {
		level = HIGH;
		cout << getName() << " is ON HIGH" << endl;
	}
	void medium() {
		level = MEDIUM;
		cout << getName() << " is ON MEDIUM" << endl;
	}
	void low() {
		level = LOW;
		cout << getName() << " is ON LOW" << endl;
	}


};

class GarageDoor : public Device {
	public:
	GarageDoor(string name) : Device(name) {}
	void on() override {
		cout << getName() << " is OPEN" << endl;
	}
	void off() override {
		cout << getName() << " is CLOSED" << endl;
	}
};

class Stereo : public Device {
	public:
	Stereo(string name) : Device(name) {}
	void on() override {
		cout << getName() << " is ON" << endl;
	}
	void off() override {
		cout << getName() << " is OFF" << endl;
	}
};