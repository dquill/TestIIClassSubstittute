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

    // make Aircraft
    Aircraft plane1("1", "192.168.0.1");
    Aircraft plane2("2", "192.168.0.2");
    Aircraft plane3("3", "192.168.0.3");
    //How do I give a threat classification to a constructor?
    //Aircraft plane1("1", "192.168.0.1", "location", TRAFFIC_ADVISORY);
    //Aircraft plane2("2", "192.168.0.2", "location", TRAFFIC_ADVISORY);
    //Aircraft plane3("3", "192.168.0.3", "location", TRAFFIC_ADVISORY);
    

    // put pointers to them in intrudingAircraft map
    intrudingAircraft[plane1.id] = &plane1;
    intrudingAircraft[plane2.id] = &plane2;
    intrudingAircraft[plane3.id] = &plane3;


    // call updateDrawnIntrudersCallback()
    updateDrawnIntrudersCallback();

    // ask intruderInstantiator to output the contents of the map
    intruderInstantiator->printDrawnIntrudersMap();


    std::cout << "Hello World!\n";
}

void printIntrudersMap() {

    static const char* EnumStrings[] = { "NON_THREAT_TRAFFIC", "PROXIMITY_INTRUDER_TRAFFIC", "TRAFFIC_ADVISORY", "RESOLUTION_ADVISORY" };

    std::cout << "Contents of interudersMap:" << std::endl;
    for (auto iter : intrudingAircraft) {

        Aircraft* intruder = iter.second;
        
        std::cout << intruder->id << std::endl;
    }
    std::cout << "End Map" << std::endl;
}


