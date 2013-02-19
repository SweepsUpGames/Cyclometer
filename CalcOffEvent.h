/*
 * CalcOffEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef CALCOFFEVENT_H_
#define CALCOFFEVENT_H_

#include "Event.h"

class CalcOffEvent: public Event{
public:
	CalcOffEvent();
	~CalcOffEvent();
	void run(Receiver* rec);
	void setType(ev::EventType et);

};

#endif /* CALCOFFEVENT_H_ */
