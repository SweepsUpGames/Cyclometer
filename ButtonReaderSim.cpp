/*
 * ButtonReader.cpp
 *
 *  Created on: Feb 15, 2013
 *
 *      Author: ajm6611
 */

#include "ButtonReaderSim.h"
#include "Constants.h"
#include "ModeEvent.h"
#include "SetEvent.h"
#include "StartStopEvent.h"

#include <iostream>
#include <hw/inout.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

ButtonReaderSim::ButtonReaderSim(){

}

ButtonReaderSim::~ButtonReaderSim(){

}

void ButtonReaderSim::trigger(Event ev) {
	dispatch.dispatch(ev);
}

void* scanButton(void* brs) {
	ButtonReaderSim* buttonReaderSim = (ButtonReaderSim*) brs;
	for (;;){
		buttonReaderSim->readButton();
	}
	return NULL;
}

void ButtonReaderSim::readButton(){
	char c = 0;
	while (std::cin.get(c)) {
		std::cout.put(c);

		switch (c) {
		case 'm':
			trigger(ModeEvent());
			std::cout<<"mode event triggered...";
			break;
		case 's':
			trigger(SetEvent());
			std::cout<<"set event triggered...";
			break;
		case 'S':
			trigger(StartStopEvent());
			std::cout<<"start-stop event triggered...";
			break;
		case 'x':
			break;
		}

		usleep(10);
	}
}

void ButtonReaderSim::start() {
	pthread_t reader;
	pthread_create(&reader, NULL, scanButton, this);
}
