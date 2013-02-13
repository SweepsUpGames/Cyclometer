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
	UpdateDisplayEvent(double current, double average);
	void run(SevenSegmetController* ssc);
private:
	double current;
	double average;
};

#endif /* UPDATEDISPLAYEVENT_H_ */
