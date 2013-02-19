/*
 * ElapsedTimeState.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef ELAPSEDTIMESTATE_H_
#define ELAPSEDTIMESTATE_H_

#include "State.h"

class ElapsedTimeState: public State{
public:
	ElapsedTimeState(int tireSize);
	Event* onEnter();
	Event* onExit();
	Event* onExit2();
	Event* giveEvent(Event* event);
	State* getNextState();
private:
	int tireSize;
};

#endif /* ELAPSEDTIMESTATE_H_ */
