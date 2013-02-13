#include "SevenSegmetController.h"
#include "UpdateDisplayEvent.h"
#include <cstdlib>
#include <iostream>



int main(int argc, char *argv[]) {
	//std::cout << "Welcome to the QNX Momentics IDE" << std::endl;

	SevenSegmetController ssc = SevenSegmetController();
	UpdateDisplayEvent disp = UpdateDisplayEvent(1.2,3.4);

	ssc.handleEvent(disp);

	//ssc.setDisplay(1.2,3.4);

	//ssc.setDisplay(948,false);
	ssc.runDisplay();

	//TODO SSC run on own thread
	//TODO add connection from generator to gate0 pin to enable counter
	//TODO add counter reader

	return EXIT_SUCCESS;
}
