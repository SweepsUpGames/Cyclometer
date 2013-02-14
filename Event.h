/*
 * Event.h
 *
 *  Created on: Feb 12, 2013
 *      Author: wkb6223
 */

#ifndef EVENT_H_
#define EVENT_H_

class SevenSegmetController;

class Event {
public:
	//TODO add State to run parameters
	Event();
	virtual ~Event();
	virtual void run(SevenSegmetController* ssc);
};

#endif /* EVENT_H_ */
