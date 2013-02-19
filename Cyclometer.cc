#include "SevenSegmetController.h"
#include "DisplayStateMachine.h"
#include "CounterReader.h"
#include "ButtonReader.h"
#include "UpdateDisplayEvent.h"
#include "Dispatcher.h"
#include "SpeedCalculator.h"
#include "DistanceCalculator.h"
#include "TimeCalculator.h"
#include "CalcStateMachine.h"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
	std::cout << "Welcome to the QNX Momentics IDE" << std::endl;

	SevenSegmetController* ssc = new SevenSegmetController();
	CounterReader* cr = new CounterReader();
	Dispatcher* dispatch = new Dispatcher();
	dispatch->start();

	ssc->setDispather(dispatch);
	ssc->startDisplay();

	DisplayStateMachine* diplay = new DisplayStateMachine(dispatch);
	SpeedCalculator* speed = new SpeedCalculator(dispatch);
	DistanceCalculator* distance = new DistanceCalculator(dispatch);
	TimeCalculator* time = new TimeCalculator(dispatch);
	ButtonReader* br = new ButtonReader();
	CalcStateMachine* csm = new CalcStateMachine(dispatch);

	br->setDispatcher(dispatch);
	br->readInput();
	cr->startCounter();
	cr->setDispatcher(dispatch);
	speed->genSpeed();
	distance->genDist();
	time->startClock();


	while(true){
		usleep(10000000);
	}

	//TODO add connection from generator to gate0 pin to enable counter
	//TODO add counter reader

	return EXIT_SUCCESS;
}
