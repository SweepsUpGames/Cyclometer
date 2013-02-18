/*
 * ModeEvent.h
 *
 *  Created on: Feb 17, 2013
 *      Author: wkb6223
 */

#ifndef MODEEVENT_H_
#define MODEEVENT_H_

#include "Event.h"

class ModeEvent: public Event{
public:
	ModeEvent();
	void run(SevenSegmetController* ssc);
};

#endif /* MODEEVENT_H_ */
