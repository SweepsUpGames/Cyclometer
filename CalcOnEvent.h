/*
 * CalcOnEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef CALCONEVENT_H_
#define CALCONEVENT_H_

#include "Event.h"

class CalcOnEvent: public Event{
public:
	CalcOnEvent();
	~CalcOnEvent();
	void run(Receiver* rec);
	void setType(ev::EventType et);


};

#endif /* CALCONEVENT_H_ */
