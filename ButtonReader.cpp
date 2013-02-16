/*
 * ButtonReader.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

void ButtonReader::trigger(Event ev) {
	dispatcher.dispatch(ev);
}

void* scanButton(void* ssc) {
	/*while (((SevenSegmetController *) ssc)->isRunning()){
	 ((SevenSegmetController *) ssc)->updateDisplay();
	 }*/

	char c;
	while (std::cin.get(c)) {
		std::cout.put(c);

		switch (c) {
		case 'm':
			trigger(new ModeEvent());
			std::cout<<"mode event triggered...";
			break;
		case 's':
			trigger(new SetEvent());
			std::cout<<"set event triggered...";
			break;
		case 'S':
			trigger(new StartStopEvent());
			std::cout<<"start-stop event triggered...";
			break;
		case 'x':
			break;
		}

		usleep(10);
	}

	return NULL;
}

void ButtonReader::start() {
	pthread_t reader;
	pthread_create(&reader, NULL, scanButton, this);
}
