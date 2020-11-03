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
    

    // put pointers to them in intrudingAircraft map


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


