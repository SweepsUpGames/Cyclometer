/*
 * Dispatcher.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#include "Dispatcher.h"

Dispatcher::Dispatcher() {

}

void Dispatcher::dispatch(Event* event) {
	eventQueue.push_back(event);
}

void subscribe(Event* event, Receiver receiver) {
	eventReceiversHashtable.insert(std::make_pair(event, receiver));
}

Dispatcher::~Dispatcher() {

}

void* eventWorker(void*) {
	while (isRunning) {
		while (!eventQueue.empty()) {
			Event ev = sscQueue.pop_front();
			std::map<ev::EventType, Receiver>::iterator it;

			for (it = eventReceiversHashtable.begin(); it != eventReceiversHashtable.end(); it++) {
				if (it->first() == ev.getEventType()) {
					it->second()->notify(ev);
				}
			}
		}

		usleep(10);
	}
	return NULL;
}

void Dispatcher::start() {
	pthread_t disp_t;
	pthread_create(&disp_t, NULL, eventWorker, NULL);
	isRunning = true;
}

void Dispatcher::stop() {
	isRunning = false;
}
