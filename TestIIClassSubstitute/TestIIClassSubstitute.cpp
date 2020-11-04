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
    Aircraft* plane1 = new Aircraft("1", "192.168.0.1"); // <- new heap allocates a plane object and returns us a pointer to it. 
    Aircraft* plane2 = new Aircraft("2", "192.168.0.2"); // there's another newer way to heap allocate as well that doesn't use new. I don't know it off the top of my head
    Aircraft* plane3 = new Aircraft("3", "192.168.0.3"); 
    

    // put pointers to them in intrudingAircraft map
    //intrudingAircraft.insert(&plane1); insert() for a map requires a key,value pair. 
    // if you really want to use insert, you need to use make_pair() to create a key,value pair. 
    // and if you want to remove the compiler warning about ignoring the object you either cast the entire call to void
    // or create a std::pair<iterator, bool> to catch the return for inspection. iterator.second would be the bool to see 
    // if the value added to the map. 
    // lets try doing an add this way just for fun, though I'd argue that just doing intrudingAircraft[plane1->id] = plane1; is easier

    typedef concurrency::concurrent_unordered_map<std::string, Aircraft*>::iterator addIterator; // create a iterator for a <string,Aircraft*> map
    // now addIterator is that iterator's type

    // create the std::pair<iterator,bool> we need to catch the result of our map insertion
    std::pair<addIterator, bool> result;

    // use std::make_pair() to make the key, value pair that the insert() function wants to get, and feed that to insert()
    result = intrudingAircraft.insert(std::make_pair(plane1->id,plane1));

    // test if the insert suceeded or failed
    if (result.second == true) {
        std::cout << "Added a plane to intrudingAircraft map" << std::endl;
    }

    // lets do these insertions the easy way, using the [] operator
    intrudingAircraft[plane2->id] = plane2;
    intrudingAircraft[plane3->id] = plane3;


    // call updateDrawnIntrudersCallback()
    updateDrawnIntrudersCallback();

    // ask intruderInstantiator to output the contents of the map
    intruderInstantiator->printDrawnIntrudersMap();


    std::cout << "Hello World!\n";
    system("pause");
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


