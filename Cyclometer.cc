#include "SevenSegmetController.h"
#include <cstdlib>
#include <iostream>



int main(int argc, char *argv[]) {
	std::cout << "Welcome to the QNX Momentics IDE" << std::endl;

	SevenSegmetController ssc = SevenSegmetController();
	ssc.runDisplay();

	return EXIT_SUCCESS;
}
