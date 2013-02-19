/*
 * DistanceCalculator.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef DISTANCECALCULATOR_H_
#define DISTANCECALCULATOR_H_

#include "Generator.h"
#include "Receiver.h"

class DistanceCalculator: public Generator, Receiver{
private:
	Dispatcher* dispatcher;
	bool km;
	bool setUp;
	bool calc;
	int tireSize;
	double totalDist;

public:
	void setKilo(bool km);
	void notify(Event* ev);
	DistanceCalculator(Dispatcher* dispatch);
	Event* makeEvent();
	void genDist();
	void setTireSize(int tire);
	void sub(ev::EventType evType, DistanceCalculator* receiver){
		dispatcher->subscribe(evType, ((Receiver*)receiver));
	}
	void trigger(Event* event){
		dispatcher->dispatch(event);
	}
	void setDispatcher(Dispatcher* dispatch){
		dispatcher = dispatch;
	}
	void addPulse(int pulses);

	double calcDist(int pules);
};

#endif /* DISTANCECALCULATOR_H_ */
