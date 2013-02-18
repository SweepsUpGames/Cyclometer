/*
 * PulseEvent.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef PULSEEVENT_H_
#define PULSEEVENT_H_

#include "Event.h"

class PulseEvent: public Event{
private:
	int pulses;

public:
	PulseEvent();
	~PulseEvent();
	void setPulses(int newPulses);
	void run(Receiver* rec);
};


#endif /* PULSEEVENT_H_ */
