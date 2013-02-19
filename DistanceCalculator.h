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
	void genDist();
	Event* makeEvent();
	void sub(ev::EventType evType, DistanceCalculator* receiver){
		dispatcher->subscribe(evType, ((Receiver*)receiver));
	}
	DistanceCalculator(Dispatcher* dispatch);
	void trigger(Event* event){
		dispatcher->dispatch(event);
	}
	double calcDist(int pules);
	void notify(Event* ev);
	void addPulse(int pulses);
	void setKilo(bool km);
	void setTireSize(int tire);
};

#endif /* DISTANCECALCULATOR_H_ */
