/*
 * Receiver.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */
#include "Receiver.h"

using namespace std;

Receiver::Receiver(Dispatcher disp){
	this.dispatcher = disp;
    dispatcher.subscribe(, this);
}

