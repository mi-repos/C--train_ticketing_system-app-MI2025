#ifndef FARECALCULATOR_H
#define FARECALCULATOR_H

#include "Station.h"
#include "Ticket.h"

class FareCalculator {
public:
    static double calculateBaseFare(int sourceZone, int destinationZone);
    static double calculateFare(int sourceZone, int destinationZone, TicketType type);
};

#endif // FARECALCULATOR_H