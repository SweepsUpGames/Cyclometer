/*
 * UpdateDistanceEvent.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef UPDATEDISTANCEEVENT_H_
#define UPDATEDISTANCEEVENT_H_

#include "Event.h"

class UpdateDistanceEvent: public Event{
public:
	UpdateDistanceEvent();
	void run(Receiver* receiver);
	void setDistance(double distance);
	double getDistance();

private:
	double distance;
};

#endif /* UPDATEDISTANCEEVENT_H_ */
