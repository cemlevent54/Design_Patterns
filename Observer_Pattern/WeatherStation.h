#pragma once
#include<iostream>
using namespace std;
#include "Observer.h"
#include<list>

class WeatherData : public Subject {
private:
	mutable list<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;
public:
	void registerObserver(Observer* o) {
		observers.push_back(o);
	}
	void removeObserver(Observer* o) {
		observers.remove(o);
	}
	void notifyObservers() const {
		list<Observer*>::iterator iter = observers.begin();
		for (list< Observer* >::iterator iter = observers.begin(); observers.end() != iter; ++iter) {
			Observer* observer = *iter;
			observer->update(temperature, humidity, pressure);
		}
	}

	void measurementChanged() {
		notifyObservers();
	}

	void setMeasurements(float _temperature, float _humidity, float _pressure) {
		temperature = _temperature;
		humidity = _humidity;
		pressure = _pressure;
		measurementChanged();
	}

	// WeatherData functions here
};

class CurrentConditionsDisplay : private Observer, DisplayElement {
private:
	float temperature;
	float humidity;
	Subject* weatherData; //
public:
	CurrentConditionsDisplay(Subject* _weatherData) : temperature(0.0), humidity(0.0) {
		weatherData = _weatherData;
		weatherData->registerObserver(this);
}
	~CurrentConditionsDisplay() {
		weatherData->removeObserver(this);
	}
	void update(float _temperature, float _humidity, float _pressure) {
		temperature = _temperature;
		humidity = _humidity;
		display();
	}
	void display() {
		cout << "Current conditions: " << temperature;
		cout << " F degrees and " << humidity;
		cout << "% humidity" << endl << endl << endl;
	}
};

class StatisticsDisplay : private Observer, DisplayElement {
private:
	float maxTemp;
	float minTemp;
	float tempSum;
	int numReadings;
	WeatherData* weatherData;
public:
	StatisticsDisplay(WeatherData* _weatherData) :
		maxTemp(0.0), minTemp(0.0), tempSum(0.0), numReadings(0.0) {
		weatherData = _weatherData;
    }
	~StatisticsDisplay() {
		weatherData->removeObserver(this);
	}
	void update(float _temp, float _humidity, float _pressure) {
		tempSum += _temp;
		numReadings++;
		if (_temp > maxTemp) {
			maxTemp = _temp;
		}
		if (_temp < minTemp) {
			minTemp = _temp;
		}
		display();
	}

	void display()  {
		cout << "Avg/Max/Min temperature = " << (tempSum / numReadings);
		cout << "/" << maxTemp << "/" << minTemp << endl << endl << endl;
	}
};

class ForeCastDisplay : private Observer, DisplayElement {
private:
	float currentPressure;
	float lastPressure;
	WeatherData* weatherData;
public:
	ForeCastDisplay(WeatherData* _weatherData) : currentPressure(29.92) {
		weatherData = _weatherData;
		weatherData->registerObserver(this);
    }

	~ForeCastDisplay() {
		weatherData->removeObserver(this);
	}

	void update(float _temp, float _humidity, float _pressure) {
		lastPressure = currentPressure;
		currentPressure = _pressure;
		
		display();
	}

	void display() {
		cout << "Forecast: ";
		if (currentPressure > lastPressure) {
			cout << "Improving weather on the way!";
		}
		else if (currentPressure == lastPressure) {
			cout << "More of the same";
		}
		else if (currentPressure < lastPressure) {
			cout << "Watch out for cooler, rainy weather";
		}
		cout << endl << endl << endl;
	}
 
};

