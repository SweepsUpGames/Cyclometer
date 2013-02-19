/*
 * SpeedCalculator.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef SPEEDCALCULATOR_H_
#define SPEEDCALCULATOR_H_

#include "Generator.h"
#include "Receiver.h"

class SpeedCalculator: public Generator, Receiver{
private:
	Dispatcher* dispatcher;
	int speeds [300];
	int input;
	int tireSize;
	bool kilo;
	bool setUp;
	bool calc;

public:
	bool isSetUp();
	SpeedCalculator(Dispatcher* dispatch);
	void setKilo(bool isKilo);
	void setTireSize(int tireSize);
	void initSpeeds();
	void genSpeed();
	Event* getSpeed();
	double getAverageSpeed();
	double clacSpeed(double count);
	void setDispatcher(Dispatcher* dispatch){
		dispatcher = dispatch;
	}

	void sub(ev::EventType evType, SpeedCalculator* receiver){
		dispatcher->subscribe(evType, ((Receiver*)receiver));
	}

	void notify(Event* ev);

	void trigger(Event* event){
		dispatcher->dispatch(event);
	}
	void addSpeed(int speed);
	double getCurrentSpeed();
};


#endif /* SPEEDCALCULATOR_H_ */
