/*
 * Receiver.h
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_


class Receiver{
public:
	Receiver(Dispatcher *dispatcher);
	void notify(Event ev);


private:
	std::list<Event> eventList;
	Dispatcher dispatcher;
};
#endif /* RECEIVER_H_ */
