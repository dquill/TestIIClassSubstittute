#include "Aircraft.h"

Aircraft::Aircraft(std::string const id, std::string const ip) : id(id), ip(ip) { }

Aircraft::Aircraft(std::string const id, std::string const ip, std::string location, ThreatClassification tc) : id(id), ip(ip),
																				location(location), threatClassification(tc) {}
