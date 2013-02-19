/*
 * UpdateElapcedTimeEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef UPDATEELAPCEDTIMEEVENT_H_
#define UPDATEELAPCEDTIMEEVENT_H_

#include "Event.h"

class UpdateElapcedTimeEvent: public Event{
public:
	UpdateElapcedTimeEvent();
	void run(Receiver* receiver);
	void setMinutes(int min);
	void setSeconds(int sec);
private:
	int minutes;
	int seconds;
};

#endif /* UPDATEELAPCEDTIMEEVENT_H_ */
