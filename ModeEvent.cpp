/*
 * ModeEvent.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#include "ModeEvent.h"
#include <iostream>

using namespace std;

ModeEvent::ModeEvent(){
	EVENT_TYPE = ev::MODE;
}

void ModeEvent::run(SevenSegmetController* ssc){
	printf("oops \n");
}

