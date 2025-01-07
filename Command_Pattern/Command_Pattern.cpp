// Command_Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Command.h"
using namespace std;
#include "RemoteControl.h"
#include "Devices.h"

int main()
{
#if 0
	RemoteControl* remoteControl = new RemoteControl();

	Light* livingRoomLight = new Light("Living Room Light");
	Light* kitchenLight = new Light("Kitchen Light");
	CeilingFan* ceilingFan = new CeilingFan("Ceiling Fan in Living Room");
	GarageDoor* garageDoor = new GarageDoor("Garage Door");
	Stereo* stereo = new Stereo("Stereo in Living Room");

	LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
	LightOnCommand* kitchenLightOn = new LightOnCommand(kitchenLight);
	LightOffCommand* kitchenLightOff = new LightOffCommand(kitchenLight);

	CeilingFanOnCommand* ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
	CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

	GarageDoorUpCommand* garageDoorOpen = new GarageDoorUpCommand(garageDoor);
	GarageDoorDownCommand* garageDoorClose = new GarageDoorDownCommand(garageDoor);

	StereoOnCommand* stereoOn = new StereoOnCommand(stereo);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remoteControl->setCommand(1, kitchenLightOn, kitchenLightOff);
	remoteControl->setCommand(2, ceilingFanOn, ceilingFanOff);
	remoteControl->setCommand(3, garageDoorOpen, garageDoorClose);
	remoteControl->setCommand(4, stereoOn, stereoOff);

	cout << remoteControl->toString() << endl;

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	
	remoteControl->onButtonWasPushed(1);
	remoteControl->offButtonWasPushed(1);

	remoteControl->onButtonWasPushed(2);
	remoteControl->offButtonWasPushed(2);

	remoteControl->onButtonWasPushed(3);
	remoteControl->offButtonWasPushed(3);

	remoteControl->onButtonWasPushed(4);
	remoteControl->offButtonWasPushed(4);
#elif 0
	RemoteControl* remoteControl = new RemoteControl();
	Light* livingRoomLight = new Light("Living Room");
	LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	
	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	cout << remoteControl->toString() << endl;
	remoteControl->undoButtonWasPushed();
	remoteControl->offButtonWasPushed(0);
	remoteControl->onButtonWasPushed(0);
	cout << remoteControl->toString() << endl;
	remoteControl->undoButtonWasPushed();

#elif 0
// ceiling fan high test
   RemoteControl* remoteControl = new RemoteControl();
   CeilingFan* ceilingFan = new CeilingFan("Living Room");
   CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
   CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
   CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

   remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
   remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

   cout << "--1--\n";
   remoteControl->onButtonWasPushed(0);
   remoteControl->offButtonWasPushed(0);
   cout << remoteControl->toString() << endl;
   remoteControl->undoButtonWasPushed();

   cout << "--2--\n";
   remoteControl->onButtonWasPushed(1);
   cout << remoteControl->toString() << endl;
   remoteControl->undoButtonWasPushed();
   
#elif 1 
// macro command test
	RemoteControl* remoteControl = new RemoteControl();
	Light* livingRoomLight = new Light("Living Room");
	Stereo* stereo = new Stereo("Living Room");
	GarageDoor* garageDoor = new GarageDoor("Garage Door");

	LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
	StereoOnCommand* stereoinLivingRoomOn = new StereoOnCommand(stereo);
	GarageDoorUpCommand* garageDoorOpen = new GarageDoorUpCommand(garageDoor);

	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
	StereoOffCommand* stereoinLivingRoomOff = new StereoOffCommand(stereo);
	GarageDoorDownCommand* garageDoorClose = new GarageDoorDownCommand(garageDoor);

	vector<Command*> partyOn;
	partyOn.push_back(livingRoomLightOn);
	partyOn.push_back(stereoinLivingRoomOn);
	partyOn.push_back(garageDoorOpen);

	vector<Command*> partyOff;
	partyOff.push_back(livingRoomLightOff);
	partyOff.push_back(stereoinLivingRoomOff);
	partyOff.push_back(garageDoorClose);

	MacroCommand* partyOnMacro = new MacroCommand(partyOn);
	MacroCommand* partyOffMacro = new MacroCommand(partyOff);

	remoteControl->setCommand(0, partyOnMacro, partyOffMacro);

	cout << remoteControl->toString() << endl;

	cout << "--- Pushing Macro On ---\n";
	remoteControl->onButtonWasPushed(0);
	cout << "--- Pushing Macro Off ---\n";
	remoteControl->offButtonWasPushed(0);

#endif 
	return 0;
}
