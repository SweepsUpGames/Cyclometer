/*
 * Dispatcher.h
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include "Event.h"
#include "Receiver.h"
#include "EventType.h"
#include <list>
#include <map>


class Receiver;

class Dispatcher {
public:
	//TODO add State to run parameters
	Dispatcher();
	~Dispatcher();
	void dispatch(Event event);
	void subscribe(ev::EventType evType, Receiver receiver);
	void start();
	void stop();
	bool isRunning();
	void runDispatch();

protected:
	std::list<Event> eventQueue;

private:
	std::map<ev::EventType, Receiver> eventReceiversHashtable;
	bool running;

};

#endif /* DISPATCHER_H_ */
