/*
 * CalcOnEvent.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "CalcOnEvent.h"

CalcOnEvent::CalcOnEvent(){
	EVENT_TYPE = ev::CALC_ON;
}

CalcOnEvent::~CalcOnEvent(){

}

void CalcOnEvent::run(Receiver* rec){

}

void CalcOnEvent::setType(ev::EventType et){
	EVENT_TYPE = et;
}
