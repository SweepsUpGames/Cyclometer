/*
 * UpdateDistanceEvent.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: wkb6223
 */

#include "UpdateDistanceEvent.h"

UpdateDistanceEvent::UpdateDistanceEvent(){
	EVENT_TYPE = ev::DIST;
}

void UpdateDistanceEvent::run(Receiver* rec){

}

void UpdateDistanceEvent::setDistance(double dist){
	distance = dist;
}

double UpdateDistanceEvent::getDistance(){
	return distance;
}
