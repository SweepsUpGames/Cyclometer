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
	void setKilo(bool isKilo);
	void notify(Event* ev);
	SpeedCalculator(Dispatcher* dispatch);
	Event* getSpeed();
	void genSpeed();
	void setTireSize(int tireSize);
	void sub(ev::EventType evType, SpeedCalculator* receiver){
		dispatcher->subscribe(evType, ((Receiver*)receiver));
	}
	void trigger(Event* event){
		dispatcher->dispatch(event);
	}
	void setDispatcher(Dispatcher* dispatch){
		dispatcher = dispatch;
	}
	void addSpeed(int speed);

	bool isSetUp();
	void initSpeeds();
	double getAverageSpeed();
	double clacSpeed(double count);
	double getCurrentSpeed();
};


#endif /* SPEEDCALCULATOR_H_ */
