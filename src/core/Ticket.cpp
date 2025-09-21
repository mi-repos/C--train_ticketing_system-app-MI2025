#include "Ticket.h"
#include <iostream>
#include <iomanip>

Ticket::Ticket(const Station& source, const Station& destination, TicketType type, double fare)
    : source(source), destination(destination), type(type), fare(fare) {}

void Ticket::printTicket() const {
    std::cout << "====================================\n";
    std::cout << "          TRAIN TICKET\n";
    std::cout << "====================================\n";
    std::cout << "From: " << source.getName() << " (Zone " << source.getZone() << ")\n";
    std::cout << "To:   " << destination.getName() << " (Zone " << destination.getZone() << ")\n";
    std::cout << "Type: ";
    switch (type) {
        case TicketType::SINGLE: std::cout << "Single"; break;
        case TicketType::RETURN: std::cout << "Return"; break;
        case TicketType::DAY_PASS: std::cout << "Day Pass"; break;
    }
    std::cout << "\n";
    std::cout << "Fare: £" << std::fixed << std::setprecision(2) << fare << "\n";
    std::cout << "====================================\n";
}

Station Ticket::getSource() const { return source; }
Station Ticket::getDestination() const { return destination; }
TicketType Ticket::getType() const { return type; }
double Ticket::getFare() const { return fare; }

SingleTicket::SingleTicket(const Station& source, const Station& destination, double fare)
    : Ticket(source, destination, TicketType::SINGLE, fare) {}

void SingleTicket::printTicket() const {
    Ticket::printTicket();
}

ReturnTicket::ReturnTicket(const Station& source, const Station& destination, double fare)
    : Ticket(source, destination, TicketType::RETURN, fare * 1.8) {} // Return is 1.8x single

void ReturnTicket::printTicket() const {
    Ticket::printTicket();
}

DayPass::DayPass(const Station& source, const Station& destination, double fare)
    : Ticket(source, destination, TicketType::DAY_PASS, fare * 2.5) {} // Day pass is 2.5x single

void DayPass::printTicket() const {
    Ticket::printTicket();
    std::cout << "Valid for unlimited travel today\n";
    std::cout << "====================================\n";
}