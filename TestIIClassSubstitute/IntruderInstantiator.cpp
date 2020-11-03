#include "IntruderInstantiator.h"



// private instance
IntruderInstantiator* IntruderInstantiator::instance = NULL;

IntruderInstantiator::IntruderInstantiator(concurrency::concurrent_unordered_map<std::string, Aircraft*>* imap) {
	intrudersMap = imap;
}


// we need to pass a reference to the intrudersmap to the class so that we know where it is. 
IntruderInstantiator* IntruderInstantiator::getIntruderInstatiator(concurrency::concurrent_unordered_map<std::string, Aircraft*>* intrudersMap) {
	if (instance == NULL) { // why is it angry about this?
		instance = new IntruderInstantiator(intrudersMap);
	}
	return instance;
}
// for when we just want to call on our instance to do things, but don't have easy access to a pointer to the intruders map.
// this function returns a pointer to the IntruderInstantiator intance if it has already be constructed.
// Returns NULL if there is no instance yet.
IntruderInstantiator* IntruderInstantiator::getIntruderInstatiator() {
	if (instance == NULL) {
		return NULL;
	}
	return instance;
}

void updateDrawnIntrudersCallback() {
	IntruderInstantiator* ii_inst = IntruderInstantiator::getIntruderInstatiator();
	if (ii_inst) {
		return ii_inst->updateDrawnIntruders();
	}
	else {
		return;
	}
}

void IntruderInstantiator::updateDrawnIntruders()
{
	//iterate through intrudersMap
	for (auto iter : *this->intrudersMap)
	{

		//if threat classification of aircraft >= TRAFFIC_ADVISORY
		if (iter.second->threatClassification >= Aircraft::ThreatClassification::TRAFFIC_ADVISORY)
		{
			//look for the aircraft in drawnIntrudersMap
			auto foundAircraft = drawnIntrudersMap.find(iter.first);

			if (foundAircraft == drawnIntrudersMap.end())
			{
				//add it to drawnIntrudersMap if it's not in there
				addDrawnIntruder(iter.second);
			}
		}
	}

	//iterate through drawnIntrudersMap
	for (auto iter = drawnIntrudersMap.cbegin(), next_iter = iter; iter != drawnIntrudersMap.cend();
		iter = next_iter)
	{
		//store next interator in case we delete the current one
		next_iter++;

		//look for the aircraft in intrudersMap
		auto foundAircraft = this->intrudersMap->find(iter->first);

		if (foundAircraft == intrudersMap->end())
		{
			//remove it from drawnIntrudersMap if it's not in intrudersMap
			removeDrawnIntruder(iter->second);
		}
		else if (iter->second->threatClassification < Aircraft::ThreatClassification::TRAFFIC_ADVISORY)
		{
			//also remove it if its threat classification is < TRAFFIC_ADVISORY now
			removeDrawnIntruder(iter->second);
		}

	}
}

void IntruderInstantiator::addDrawnIntruder(Aircraft* intruder)
{
	//add the intruder to drawnIntrudersMap
	(drawnIntrudersMap)[intruder->id] = intruder;
}

void IntruderInstantiator::removeDrawnIntruder(Aircraft* intruder)
{
	//remove the intruder from drawnIntrudersMap
	drawnIntrudersMap.unsafe_erase(intruder->id);
}

void IntruderInstantiator::printDrawnIntrudersMap() {

	static const char * EnumStrings[] = { "NON_THREAT_TRAFFIC", "PROXIMITY_INTRUDER_TRAFFIC", "TRAFFIC_ADVISORY", "RESOLUTION_ADVISORY" };

	std::cout << "Contents of drawnInterudersMap:" << std::endl;
	for (auto iter : drawnIntrudersMap) {

		Aircraft* drawnintruder = iter.second;
		std::cout << ThreatClassification::drawnintruder->threatClassification << std::endl;
		std::cout << drawnintruder->id <<  ", threat: " << drawnintruder->threatClassification << std::endl;
	}
	std::cout << "End Map" << std::endl;
}
