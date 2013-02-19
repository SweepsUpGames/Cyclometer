/*
 * CalcOffEvent.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "CalcOffEvent.h"

CalcOffEvent::CalcOffEvent(){
	EVENT_TYPE = ev::CALC_OFF;
}

void CalcOffEvent::run(Receiver* rec){

}

void CalcOffEvent::setType(ev::EventType et){
	EVENT_TYPE = et;
}
