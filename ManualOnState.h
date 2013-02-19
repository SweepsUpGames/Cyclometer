/*
 * ManualOnState.h
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#ifndef MANUALONSTATE_H_
#define MANUALONSTATE_H_

#include "State.h"

class ManualOnState: public State{
public:
	ManualOnState();
	Event* onEnter();
	Event* onEnter2();
	Event* onEnter3();
	Event* onExit();
	Event* onExit2();
	Event* onExit3();
	Event* giveEvent(Event* event);
	State* getNextState();

};

#endif /* MANUALONSTATE_H_ */
