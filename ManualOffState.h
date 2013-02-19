/*
 * ManualOffState.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef MANUALOFFSTATE_H_
#define MANUALOFFSTATE_H_

#include "State.h"

class ManualOffState: public State{
public:
	ManualOffState();
	Event* onEnter();
	Event* onExit();
	Event* onExit2();
	Event* onExit3();
	Event* giveEvent(Event* event);
	State* getNextState();

};

#endif /* MANUALOFFSTATE_H_ */
