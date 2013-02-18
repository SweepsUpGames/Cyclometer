#include "SevenSegmetController.h"
#include "DisplayStateMachine.h"
#include "CounterReader.h"
#include "ButtonReader.h"
#include "UpdateDisplayEvent.h"
#include "Dispatcher.h"
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




	ButtonReader* br = new ButtonReader();
	br->setDispatcher(dispatch);
	br->readInput();
	cr->startCounter();
	cr->setDispatcher(dispatch);


	double count = 0.0;

	while(true){
		count = count + 0.1;
		if (count > 10 ){
			count = 0.0;
		}
		usleep(1000000);
	}

	//TODO add connection from generator to gate0 pin to enable counter
	//TODO add counter reader

	return EXIT_SUCCESS;
}
