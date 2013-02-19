/*
 * UpdateSpeedEvent.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef UPDATESPEEDEVENT_H_
#define UPDATESPEEDEVENT_H_

#include "Event.h"

class UpdateSpeedEvent: public Event{
private:
	double current;
	double average;

public:
	UpdateSpeedEvent();
	void run(Receiver* receiver);
	void setAverage(double newAverage);
	void setCurrent(double newCurrent);
	double getAverage();
	double getCurrent();

};

#endif /* UPDATESPEEDEVENT_H_ */
