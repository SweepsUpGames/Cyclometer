/*
 * Dispatcher.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */

#include "Dispatcher.h"
#include <pthread.h>
#include <unistd.h>

Dispatcher::Dispatcher() {

}

void Dispatcher::dispatch(Event event) {
	printf("received event\n");
	eventQueue.push_back(event);
}

void Dispatcher::subscribe(ev::EventType evType, Receiver receiver) {
	eventReceiversHashtable.insert(std::make_pair(evType, receiver));
}

Dispatcher::~Dispatcher() {

}

void* eventWorker(void* disp) {
	Dispatcher* dispatcher = (Dispatcher*)disp;
	while (dispatcher->isRunning()) {
		dispatcher->runDispatch();
		usleep(10);
	}
	return NULL;
}

void Dispatcher::runDispatch(){
	//printf("dispatch is running\n");
	if (!eventQueue.empty()) {
		printf("seen event\n");
		Event ev = eventQueue.front();
		eventQueue.pop_front();
		std::map<ev::EventType, Receiver>::iterator it;
		for (it = eventReceiversHashtable.begin(); it != eventReceiversHashtable.end(); it++) {
			if (it->first == ev.getEventType()) {
				((Receiver)(it->second)).notify(ev);
			}
		}
	}
}

void Dispatcher::start() {
	pthread_t disp_t;
	running = true;
	pthread_create(&disp_t, NULL, eventWorker, this);
}

void Dispatcher::stop() {
	running = false;
}

bool Dispatcher::isRunning(){
	return running;
}
