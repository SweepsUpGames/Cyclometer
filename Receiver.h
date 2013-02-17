/*
 * Receiver.h
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "Event.h"
#include <list>

using namespace std;

class Dispatcher;
class Receiver{
public:
	Receiver();
	void notify(Event ev);
	void setDispather(Dispatcher *dispatcher);

private:
	std::list<Event> eventList;
	Dispatcher* dispatcher;
};
#endif /* RECEIVER_H_ */
