/*
 * TimeCalculator.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef TIMECALCULATOR_H_
#define TIMECALCULATOR_H_

#include "Generator.h"
#include "Receiver.h"
#include <time.h>

class TimeCalculator: public Generator, Receiver{
public:
	TimeCalculator(Dispatcher* dispatch);
	void notify(Event* ev);
	void startClock();
	void grabTime();
	Event* getTime();
	double getCurrentTime();
	void trigger(Event* event){
		dispatcher->dispatch(event);
	}
	void setDispatcher(Dispatcher* dispatch){
		dispatcher = dispatch;
	}

private:
	Dispatcher* dispatcher;
	bool calc;
	time_t startTime;
	time_t recTime;

};

#endif /* TIMECALCULATOR_H_ */
