/*
 * TireSizeEvent.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef TIRESIZEEVENT_H_
#define TIRESIZEEVENT_H_

#include "Event.h"

class TireSizeEvent: public Event{
private:
	int tireSize;
public:
	TireSizeEvent();
	void setType(ev::EventType ev);
	void setTireSize(int tire);
	void run(Receiver* receiver);
};

#endif /* TIRESIZEEVENT_H_ */
