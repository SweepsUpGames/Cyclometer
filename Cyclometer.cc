#include "SevenSegmetController.h"
#include <cstdlib>
#include <iostream>



int main(int argc, char *argv[]) {
	//std::cout << "Welcome to the QNX Momentics IDE" << std::endl;

	SevenSegmetController ssc = SevenSegmetController();
	ssc.setDisplay(134, false);
	ssc.runDisplay();

	//TODO SSC run on own thread
	//TODO add connection from generator to gate0 pin to enable counter
	//TODO add counter reader

	return EXIT_SUCCESS;
}
