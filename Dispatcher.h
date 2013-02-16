/*
 * Dispatcher.h
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_

class Dispatcher {
public:
	//TODO add State to run parameters
	Dispatcher();
	~Dispatcher();
	void dispatch(Event* event);
	void subscribe(ev::EventType evType, Receiver receiver);
	void start();
	void stop();
private:
	std::map<ev::EventType, Receiver> eventReceiversHashtable;
	std::list<Event*> eventQueue;
	bool isRunning;
};

#endif /* DISPATCHER_H_ */
