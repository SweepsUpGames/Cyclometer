/*
 * AutoEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef AUTOEVENT_H_
#define AUTOEVENT_H_

#include "Event.h"

class AutoEvent: public Event{
public:
	AutoEvent();
	void run(Receiver* receiver);
};

#endif /* AUTOEVENT_H_ */
