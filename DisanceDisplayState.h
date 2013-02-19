/*
 * DisanceDisplayState.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef DISANCEDISPLAYSTATE_H_
#define DISANCEDISPLAYSTATE_H_

#include "State.h"

class DisanceDisplayState: public State{
public:
	DisanceDisplayState(int tire);
	Event* onEnter();
	Event* onExit();
	Event* onExit2();
	Event* onExit3();
	Event* giveEvent(Event* event);
	State* getNextState();
private:
	bool tire;
	int tireSize;
};

#endif /* DISANCEDISPLAYSTATE_H_ */
