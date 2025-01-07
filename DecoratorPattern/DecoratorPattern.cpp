#include <iostream>
using namespace std;
#include "Coffee.h"
#include "Condiment.h"

int main()
{
	cout << "DECORATOR PATTERN TESTS" << endl;

	

	Beverage* beverage = new Espresso; // order an espresso (polimorfizm)
	cout << beverage->getDescription() << "  $" << beverage->cost() << endl;

	Beverage* beverage2 = new DarkRoast; // order dark roast
	beverage2 = new Mocha(beverage2);  // wrap it with a mocha
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);

	cout << beverage2->getDescription() + "  $" << beverage2->cost() << endl;

	Beverage* beverage3 = new HouseBlend;
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	cout << beverage3->getDescription() + " $" << beverage3->cost() << endl;

}
