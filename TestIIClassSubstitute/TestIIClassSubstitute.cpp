// TestIIClassSubstitute.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Aircraft.h"
#include "IntruderInstantiator.h"

concurrency::concurrent_unordered_map<std::string, Aircraft*> intrudingAircraft;
IntruderInstantiator* intruderInstantiator;
void printIntrudersMap();

int main()
{

    intruderInstantiator = IntruderInstantiator::getIntruderInstatiator(&intrudingAircraft);

    // make Aircrafts

    // saying Aircraft plane("1", "192.168.0.1"); stack allocates an aircraft object. Not something we want to do if we are going to pass the pointer to that object out of this stack frame
    Aircraft* plane1 = new Aircraft("1", Aircraft::ThreatClassification::TRAFFIC_ADVISORY); // <- new heap allocates a plane object and returns us a pointer to it. 
    Aircraft* plane2 = new Aircraft("2", Aircraft::ThreatClassification::RESOLUTION_ADVISORY); // there's another newer way to heap allocate as well that doesn't use new. I don't know it off the top of my head
    Aircraft* plane3 = new Aircraft("3", Aircraft::ThreatClassification::RESOLUTION_ADVISORY);

    plane1->threatClassification = Aircraft::ThreatClassification::TRAFFIC_ADVISORY;
    plane2->threatClassification = Aircraft::ThreatClassification::RESOLUTION_ADVISORY;


    intrudingAircraft[plane1->id] = plane1;
    intrudingAircraft[plane2->id] = plane2;
     
    // call updateDrawnIntrudersCallback()
    updateDrawnIntrudersCallback();

    // ask intruderInstantiator to output the contents of the map
    intruderInstantiator->printDrawnIntrudersMap();




    std::cout << "Hello World!\n";
}

std::string getThreatClass(Aircraft::ThreatClassification TC) {
    string placetostoreit
    switch (intruder->threatClassification)
            case: Aircraft::ThreatClassification::NON_THREAT_TRAFFIC
        placetostore it =std::string("NON_THREAT_TRAFFIC");
    break;
            case: 
}

void printIntrudersMap() {

    //static const char* EnumStrings[] = { "NON_THREAT_TRAFFIC", "PROXIMITY_INTRUDER_TRAFFIC", "TRAFFIC_ADVISORY", "RESOLUTION_ADVISORY" };

    std::cout << "Contents of interudersMap:" << std::endl;
    for (auto iter : intrudingAircraft) {

        Aircraft* intruder = iter.second;
        


        std::cout << intruder->id  << std::endl;
    }
    std::cout << "End Map" << std::endl;
}


