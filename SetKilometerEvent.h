/*
 * SetKilometerEvent.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef SETKILOMETEREVENT_H_
#define SETKILOMETEREVENT_H_

#include "Event.h"

class SetKilometerEvent: public Event{
public:
	SetKilometerEvent();
	void run(Receiver* receiver);
	void setKilometers(bool isKilometers);

private:
	bool km;
};
#endif /* SETKILOMETEREVENT_H_ */
