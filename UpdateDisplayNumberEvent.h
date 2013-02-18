/*
 * UpdateDisplayNumberEvent.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef UPDATEDISPLAYNUMBEREVENT_H_
#define UPDATEDISPLAYNUMBEREVENT_H_

#include "Event.h"

class UpdateDisplayNumberEvent: public Event{
public:
	UpdateDisplayNumberEvent();
	void run(Receiver* ssc);
	void setNumber(int newNumber);
	void setLeadingZeros(bool newLeadingZeros);

private:
	int number;
	bool leadingZeros;
};

#endif /* UPDATEDISPLAYNUMBEREVENT_H_ */
