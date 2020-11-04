#pragma once

#include<iostream>
#include<concrt.h>
#include<concurrent_unordered_map.h>

#include "Aircraft.h"

void updateDrawnIntrudersCallback();

class IntruderInstantiator
{
private:

	static IntruderInstantiator* instance;



	//map held inside the class
	concurrency::concurrent_unordered_map<std::string, Aircraft*> drawnIntrudersMap;

	//pointer to a map held outside the class
	concurrency::concurrent_unordered_map<std::string, Aircraft*>* intrudersMap;
	IntruderInstantiator(concurrency::concurrent_unordered_map<std::string, Aircraft*>*);

public:
	static IntruderInstantiator* getIntruderInstatiator(concurrency::concurrent_unordered_map<std::string, Aircraft*>* intrudersMap);
	static IntruderInstantiator* getIntruderInstatiator();
	void printDrawnIntrudersMap();
	void updateDrawnIntruders();
	void addDrawnIntruder(Aircraft*);
	void removeDrawnIntruder(Aircraft*);


};

