#include "SevenSegmetController.h"
#include "CounterReader.h"
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

	ssc->startDisplay();
	ssc->setDispather(dispatch);

	//ButtonReader* br = new ButtonReader();
	//br->readInput();
	cr->startCounter();
	cr->setDispatcher(*dispatch);


	UpdateDisplayEvent disp = UpdateDisplayEvent();

	double count = 0.0;

	while(true){
		//disp.setCurrent(count);
		//disp.setAverage(3.4);
		//ssc->notify(disp);
		count = count + 0.1;
		if (count > 10 ){
			count = 0.0;
		}
		//printf("value %i\n",cr->checkCounter());
		usleep(1000000);
	}

	//TODO add connection from generator to gate0 pin to enable counter
	//TODO add counter reader

	return EXIT_SUCCESS;
}
