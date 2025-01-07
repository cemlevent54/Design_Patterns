#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Devices.h"
#include <vector>


class Command {
public:
    virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Command() = default; 
};

class NoCommand : public Command {
public:
	void execute() {
		cout << "No Command" << endl;
	}
	void undo() {
		cout << "No Command" << endl;
	}
};

class LightOffCommand : public Command {
	Light* light;
	public:
	LightOffCommand(Light* light) {
		this->light = light;
	}
	void execute() override {
		light->off();
	}
	void undo() override {
		light->on();
	}
};

class LightOnCommand : public Command {
	Light* light;
	public:
	LightOnCommand(Light* light) {
		this->light = light;
	}
	void execute() override {
		light->on();
	}
	void undo() override {
		light->off();
	}
};

class CeilingFanOffCommand : public Command {
	CeilingFan* ceilingFan;
	public:
	CeilingFanOffCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	void execute() override  {
		ceilingFan->off();
	}
	void undo() override {
		ceilingFan->on();
	}
};

class CeilingFanOnCommand : public Command {
	CeilingFan* ceilingFan;
	public:
	CeilingFanOnCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	void execute() override {
		ceilingFan->on();
	}
	void undo() override {
		ceilingFan->off();
	}
};

class GarageDoorDownCommand : public Command {
	GarageDoor* garageDoor;
	public:
	GarageDoorDownCommand(GarageDoor* garageDoor) {
		this->garageDoor = garageDoor;
	}
	void execute() override {
		garageDoor->off();
	}
	void undo() override {
		garageDoor->on();
	}
};

class GarageDoorUpCommand : public Command {
	GarageDoor* garageDoor;
	public:
	GarageDoorUpCommand(GarageDoor* garageDoor) {
		this->garageDoor = garageDoor;
	}
	void execute() override {
		garageDoor->on();
	}
	void undo() override {
		garageDoor->off();
	}
};

class StereoOffCommand : public Command {
	Stereo* stereo;
	public:
	StereoOffCommand(Stereo* stereo) {
		this->stereo = stereo;
	}
	void execute() override {
		stereo->off();
	}
	void undo() override {
		stereo->on();
	}
};

class StereoOnCommand : public Command {
	Stereo* stereo;
	public:
	StereoOnCommand(Stereo* stereo) {
		this->stereo = stereo;
	}
	void execute() override {
		stereo->on();
	}
	void undo() override {
		stereo->off();
	}
};

class CeilingFanHighCommand : public Command {
private:
	CeilingFan* ceilingFan;
	mutable int prevSpeed;
public:
	CeilingFanHighCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
		prevSpeed = ceilingFan->getSpeed();
	}
	void execute() override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->high();
	}
	void undo() override {
		if (prevSpeed == CeilingFan::HIGH) {
			ceilingFan->high();
		} else if (prevSpeed == CeilingFan::MEDIUM) {
			ceilingFan->medium();
		} else if (prevSpeed == CeilingFan::LOW) {
			ceilingFan->low();
		} else if (prevSpeed == CeilingFan::OFF) {
			ceilingFan->off();
		}
	}
};

class CeilingFanMediumCommand : public Command {
private:
	CeilingFan* ceilingFan;
	mutable int prevSpeed;
public:
	CeilingFanMediumCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
		prevSpeed = ceilingFan->getSpeed();
	}
	void execute() override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}
	void undo() override {
		if (prevSpeed == CeilingFan::HIGH) {
			ceilingFan->high();
		}
		else if (prevSpeed == CeilingFan::MEDIUM) {
			ceilingFan->medium();
		}
		else if (prevSpeed == CeilingFan::LOW) {
			ceilingFan->low();
		}
		else if (prevSpeed == CeilingFan::OFF) {
			ceilingFan->off();
		}
	}
};

class MacroCommand : public Command {
private:
	vector<Command*> commands;
public:
	MacroCommand(std::vector<Command*> command) :commands(command) { }

	void execute() override {
		for (int i = 0; i < commands.size(); i++) {
			commands[i]->execute();
		}
	}
	void undo()override {
		for (int i = 0; i < commands.size(); i++) {
			commands[i]->undo();
		}
	}

};