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
	Event* onEnter();
	Event* giveEvent(Event* event);
private:
	int tireSize;
};

#endif /* SELECTCIRCUMFERANCESIZESTATE_H_ */
