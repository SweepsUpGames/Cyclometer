/*
 * UpdateDisplaySMEvent.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef UPDATEDISPLAYSMEVENT_H_
#define UPDATEDISPLAYSMEVENT_H_

#include "Event.h"

class UpdateDisplaySMEvent: public Event{
public:
	UpdateDisplaySMEvent();
	void run(Receiver* receiver);
};

#endif /* UPDATEDISPLAYSMEVENT_H_ */
