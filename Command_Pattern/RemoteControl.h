#pragma once
#include <iostream>
#include <string>
#include "Command.h"
// for stringstream
#include <sstream>

class RemoteControl {
private:
    static const int SLOTS = 7;
    Command* onCommands[SLOTS];
    Command* offCommands[SLOTS];
    Command* noCommand;
    mutable Command* undoCommand;
public:
    RemoteControl() {
        noCommand = new NoCommand();
        for (int i = 0; i < SLOTS; i++) {
            onCommands[i] = noCommand;
            offCommands[i] = noCommand;
        }
        undoCommand = noCommand;
    }
    ~RemoteControl() {
        for (int i = 0; i < SLOTS; i++) {
            if (onCommands[i] != noCommand) delete onCommands[i];
            if (offCommands[i] != noCommand) delete offCommands[i];
        }
        delete noCommand;
    }
    void setCommand(int slot, Command* onCommand, Command* offCommand) {
        if (onCommands[slot] != noCommand) delete onCommands[slot];
        if (offCommands[slot] != noCommand) delete offCommands[slot];
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
	}
    void onButtonWasPushed(int slot) {
		onCommands[slot]->execute();
        undoCommand = onCommands[slot];
	}
    void offButtonWasPushed(int slot) {
		offCommands[slot]->execute();
        undoCommand = offCommands[slot];
	}
    void undoButtonWasPushed() {
		undoCommand->undo();
	}
    string toString() {
        stringstream value;
        value << "\n------ Remote Control ------\n";
        for (int i = 0; i < SLOTS; i++) {
			value << "[slot " << i << "] " << typeid(*onCommands[i]).name() << "    " << typeid(*offCommands[i]).name() << "\n";
		}
        value << "[undo] " << typeid(*undoCommand).name() << endl;
        return value.str();
	}
};