#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>

class Station {
private:
    std::string name;
    int zone;

public:
    Station(const std::string& name, int zone);
    
    std::string getName() const;
    int getZone() const;
    
    static std::vector<Station> loadStations(const std::string& filename);
    static Station findStation(const std::vector<Station>& stations, const std::string& name);
};

#endif // STATION_H