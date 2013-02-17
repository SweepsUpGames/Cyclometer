/*
 * UpdateDisplayEvent.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef UPDATEDISPLAYEVENT_H_
#define UPDATEDISPLAYEVENT_H_

#include "Event.h"

class UpdateDisplayEvent: public Event{
public:
	UpdateDisplayEvent();
	void run(SevenSegmetController* ssc);
	void setCurrent(double newCurrent);
	void setAverage(double newAverage);
private:
	double current;
	double average;
};

#endif /* UPDATEDISPLAYEVENT_H_ */
