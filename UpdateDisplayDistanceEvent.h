/*
 * UpdateDisplayDistanceEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef UPDATEDISPLAYDISTANCEEVENT_H_
#define UPDATEDISPLAYDISTANCEEVENT_H_

#include "Event.h"

class UpdateDisplayDistanceEvent: public Event{
public:
	UpdateDisplayDistanceEvent();
	void run(Receiver* receiver);
	void setDist(double dist);

private:
	double dist;
};

#endif /* UPDATEDISPLAYDISTANCEEVENT_H_ */
