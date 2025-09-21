#include "Station.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>

Station::Station(const std::string& name, int zone) : name(name), zone(zone) {}

std::string Station::getName() const {
    return name;
}

int Station::getZone() const {
    return zone;
}

std::vector<Station> Station::loadStations(const std::string& filename) {
    std::vector<Station> stations;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open stations file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        int zone;
        
        if (std::getline(iss, name, ',') && (iss >> zone)) {
            stations.emplace_back(name, zone);
        }
    }
    
    return stations;
}

Station Station::findStation(const std::vector<Station>& stations, const std::string& name) {
    for (const auto& station : stations) {
        if (station.getName() == name) {
            return station;
        }
    }
    throw std::runtime_error("Station not found: " + name);
}