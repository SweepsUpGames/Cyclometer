/*
 * SetEvent.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: ajm6611
 */
#include "Event.h"
#include "EventType.h"

class SetEvent : public Event{
      SetEvent::SetEvent(){
    	this.EVENT_TYPE = ev::SET;
      }

};
