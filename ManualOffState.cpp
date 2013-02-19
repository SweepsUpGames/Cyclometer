/*
 * ManualOffState.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "ManualOffState.h"
#include "CalcOffEvent.h"

ManualOffState::ManualOffState(){

}

Event* ManualOffState::onEnter(){
	CalcOffEvent* calcOff = new CalcOffEvent();
	return calcOff;
}

Event* ManualOffState::onEnter2(){
	CalcOffEvent* calcOff = new CalcOffEvent();
	calcOff->setType(ev::CALC_OFF2);
	return calcOff;
}

Event* ManualOffState::onEnter3(){
	CalcOffEvent* calcOff = new CalcOffEvent();
	calcOff->setType(ev::CALC_OFF3);
	return calcOff;
}

Event* ManualOffState::onExit(){
	return NULL;
}

Event* ManualOffState::onExit2(){
	return NULL;

}

Event* ManualOffState::onExit3(){
	return NULL;

}

Event* ManualOffState::giveEvent(Event* event){
	return NULL;

}

State* ManualOffState::getNextState(){
	return NULL;

}
