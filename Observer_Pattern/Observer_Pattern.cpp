#include <iostream>
using namespace std;
#include "Observer.h"
#include "WeatherStation.h"


int main()
{
	WeatherData* weatherData = new WeatherData(); // subject 

	CurrentConditionsDisplay* currentDisplay =
		new CurrentConditionsDisplay(weatherData); // observer

	StatisticsDisplay* statisticsDisplay =
		new StatisticsDisplay(weatherData); // observer

	ForeCastDisplay* forecastDisplay =
		new ForeCastDisplay(weatherData); // observer

	//delete forecastDisplay; // not display forecast
	//delete currentDisplay; // not display current conditions
	weatherData->setMeasurements(80, 65, 30.4); // notifies observers
	weatherData->setMeasurements(82, 70, 29.2);
	weatherData->setMeasurements(78, 90, 29.2);

	


}