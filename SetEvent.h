/*
 * SetEvent.h
 *
 *  Created on: Feb 17, 2013
 *      Author: wkb6223
 */

#ifndef SETEVENT_H_
#define SETEVENT_H_

#include "Event.h"

class SetEvent: public Event{
public:
	SetEvent();
	void run(Receiver* receiver);
};

#endif /* SETEVENT_H_ */
