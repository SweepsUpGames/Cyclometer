/*
 * TimeEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef TIMEEVENT_H_
#define TIMEEVENT_H_

#include "Event.h"

class TimeEvent: public Event{
public:
	TimeEvent();
	void run(Receiver* receiver);
	void setMinutes(int min);
	void setSeconds(int sec);
	int getMinutes();
	int getSeconds();

private:
	int minutes;
	int seconds;
};

#endif /* TIMEEVENT_H_ */
