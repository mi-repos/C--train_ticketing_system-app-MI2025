#include "FareCalculator.h"
#include <cmath>

double FareCalculator::calculateBaseFare(int sourceZone, int destinationZone) {
    int zoneDifference = std::abs(sourceZone - destinationZone);
    
    // Base fare structure (simplified)
    if (zoneDifference == 0) {
        return 2.50; // Same zone
    } else if (zoneDifference == 1) {
        return 3.50; // 1 zone difference
    } else if (zoneDifference == 2) {
        return 4.50; // 2 zones difference
    } else {
        return 5.50 + (zoneDifference - 3) * 1.00; // Additional zones
    }
}

double FareCalculator::calculateFare(int sourceZone, int destinationZone, TicketType type) {
    double baseFare = calculateBaseFare(sourceZone, destinationZone);
    
    switch (type) {
        case TicketType::SINGLE:
            return baseFare;
        case TicketType::RETURN:
            return baseFare * 1.8; // Return ticket discount
        case TicketType::DAY_PASS:
            return baseFare * 2.5; // Day pass price
        default:
            return baseFare;
    }
}