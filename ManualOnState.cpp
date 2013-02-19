/*
 * ManualOnState.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "ManualOnState.h"
#include "ManualOffState.h"
#include "CalcOnEvent.h"

ManualOnState::ManualOnState(){

}

Event* ManualOnState::onEnter(){
	printf("first\n");
	CalcOnEvent* calcOn = new CalcOnEvent();
	return calcOn;
}

Event* ManualOnState::onEnter2(){
	printf("second\n");
	CalcOnEvent* calcOn = new CalcOnEvent();
	calcOn->setType(ev::CALC_ON2);
	return calcOn;
}

Event* ManualOnState::onEnter3(){
	printf("third\n");
	CalcOnEvent* calcOn = new CalcOnEvent();
	calcOn->setType(ev::CALC_ON3);
	return calcOn;
}

Event* ManualOnState::onExit(){
	return NULL;
}

Event* ManualOnState::onExit2(){
	return NULL;

}

Event* ManualOnState::onExit3(){
	return NULL;

}

Event* ManualOnState::giveEvent(Event* event){
	return NULL;

}

State* ManualOnState::getNextState(){
	return new ManualOffState();

}
