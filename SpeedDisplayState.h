/*
 * SpeedDisplayState.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef SPEEDDISPLAYSTATE_H_
#define SPEEDDISPLAYSTATE_H_

#include "State.h"

class SpeedDisplayState: public State{
public:
	SpeedDisplayState(int tire);
	Event* onEnter();
	Event* onExit();
	Event* onExit2();
	Event* giveEvent(Event* event);
	State* getNextState();
private:
	int tireSize;
};

#endif /* SPEEDDISPLAYSTATE_H_ */
