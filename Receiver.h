/*
 * Receiver.h
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "Dispatcher.h"
#include "Event.h"
#include <list>

using namespace std;

class Dispatcher;
class Receiver{
public:
	Receiver();
	virtual void notify(Event ev);
	void setDispather(Dispatcher *dispatcher);

protected:
	std::list<Event> eventList;
	Dispatcher* dispatcher;
};
#endif /* RECEIVER_H_ */
