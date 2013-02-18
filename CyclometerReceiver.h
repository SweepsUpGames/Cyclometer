/*
 * Receiver.h
 *
 *  Created on: Feb 13, 2013
 *      Author: wkb6223
 */

#ifndef CYCLOMETERRECEIVER_H_
#define CYCLOMETERRECEIVER_H_

#include "Event.h"
#include <list>


class CyclometerReceiver{
private:
	std::list<Event*> eventQueue;
public:
	CyclometerReceiver();
	virtual void handleEvent ( Event* event );
};

#endif /* CYCLOMETERRECEIVER_H_ */
