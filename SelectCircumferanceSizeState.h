/*
 * SelectCircumferanceSizeState.h
 *
 *  Created on: Feb 18, 2013
 *      Author: wkb6223
 */

#ifndef SELECTCIRCUMFERANCESIZESTATE_H_
#define SELECTCIRCUMFERANCESIZESTATE_H_

#include "State.h"

class SelectCircumferanceSizeState: public State{
public:
	SelectCircumferanceSizeState();
	SelectCircumferanceSizeState(int tire);
	Event* onEnter();
	Event* onExit();
	Event* onExit2();
	Event* onExit3();
	Event* giveEvent(Event* event);
	State* getNextState();

private:
	int tireSize;
	bool outside;
};

#endif /* SELECTCIRCUMFERANCESIZESTATE_H_ */
