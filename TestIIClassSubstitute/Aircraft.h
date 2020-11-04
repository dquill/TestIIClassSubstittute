#pragma once
#include <string>


class Aircraft
{
public: 

	enum class ThreatClassification { NON_THREAT_TRAFFIC, PROXIMITY_INTRUDER_TRAFFIC, TRAFFIC_ADVISORY, RESOLUTION_ADVISORY };
	Aircraft(Aircraft const& that);
	Aircraft(std::string const id);
	Aircraft(std::string const id, ThreatClassification tc);

	std::string id;

	
	ThreatClassification threatClassification = Aircraft::ThreatClassification::NON_THREAT_TRAFFIC;

};

