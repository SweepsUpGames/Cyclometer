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
	SpeedDisplayState();
	Event* onEnter();
	Event* onExit();
	Event* giveEvent(Event* event);
	State* getNextState();
};

#endif /* SPEEDDISPLAYSTATE_H_ */
