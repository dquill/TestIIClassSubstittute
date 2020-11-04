#include "Aircraft.h"

Aircraft::Aircraft(std::string const id) : id(id) { }

Aircraft::Aircraft(std::string const id, ThreatClassification tc) : id(id),  threatClassification(tc) {}
