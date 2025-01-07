// Strategy_Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "Duck.h"

int main()
{
	Duck* mallard = new MallardDuck();
	mallard->performQuack();
	mallard->performFly();
	Duck* model = new ModelDuck();
	model->performFly();
	model->setFlyBehavior(new FlyRocketPowered()); 
	model->performFly();
	return 0;
}
