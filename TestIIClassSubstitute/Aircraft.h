#pragma once
#include <string>


class Aircraft
{
public: 

	enum class ThreatClassification { NON_THREAT_TRAFFIC, PROXIMITY_INTRUDER_TRAFFIC, TRAFFIC_ADVISORY, RESOLUTION_ADVISORY };
	Aircraft(Aircraft const& that);
	Aircraft(std::string const id, std::string const ip);
	Aircraft(std::string const id, std::string const ip, std::string location, ThreatClassification tc);

	std::string id;
	std::string ip;
	std::string location;

	
	ThreatClassification threatClassification = Aircraft::ThreatClassification::NON_THREAT_TRAFFIC;

};

