/*
 * Event.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "EventType.h"
#include "Receiver.h"

class Receiver;
class Event {
public:
	//TODO add State to run parameters
	Event();
	virtual ~Event();
	virtual void run(Receiver* receiver)=0;
	ev::EventType getEventType() {
		return EVENT_TYPE;
	}

protected:
	ev::EventType EVENT_TYPE;
};

#endif /* EVENT_H_ */
