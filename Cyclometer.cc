#include "SevenSegmetController.h"
#include "ButtonReader.h"
#include "UpdateDisplayEvent.h"
#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
	std::cout << "Welcome to the QNX Momentics IDE" << std::endl;

	SevenSegmetController* ssc = new SevenSegmetController();
	ssc->startDisplay();

	ButtonReader* br = new ButtonReader();
	br->readInput();
	//CounterReader* cr = new CounterReader();

	UpdateDisplayEvent* disp = new UpdateDisplayEvent();

	double count = 0.0;

	while(true){
		disp->setCurrent(count);
		disp->setAverage(3.4);
		ssc->handleEvent(disp);
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
