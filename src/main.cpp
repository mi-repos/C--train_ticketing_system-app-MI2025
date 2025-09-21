#include <iostream>
#include <memory>
#include <filesystem>
#include "core/Station.h"
#include "core/Ticket.h"
#include "core/FareCalculator.h"
#include "utils/InputHandler.h"

namespace fs = std::filesystem;

int main() {
    try {
        // Get the current executable path and construct data file path
        fs::path dataPath = fs::current_path() / "data" / "stations.txt";
        
        // Load stations from file
        auto stations = Station::loadStations(dataPath.string());
        
        std::cout << "====================================\n";
        std::cout << "   TRAIN TICKETING SYSTEM\n";
        std::cout << "====================================\n\n";
        
        // Select source station
        auto source = InputHandler::selectStation(stations, "Select SOURCE station:");
        
        // Select destination station
        auto destination = InputHandler::selectStation(stations, "Select DESTINATION station:");
        
        // Select ticket type
        auto ticketType = InputHandler::selectTicketType();
        
        // Calculate fare
        double fare = FareCalculator::calculateFare(
            source.getZone(), 
            destination.getZone(), 
            ticketType
        );
        
        // Create ticket
        std::unique_ptr<Ticket> ticket;
        switch (ticketType) {
            case TicketType::SINGLE:
                ticket = std::make_unique<SingleTicket>(source, destination, fare);
                break;
            case TicketType::RETURN:
                ticket = std::make_unique<ReturnTicket>(source, destination, fare);
                break;
            case TicketType::DAY_PASS:
                ticket = std::make_unique<DayPass>(source, destination, fare);
                break;
        }
        
        // Print ticket
        std::cout << "\n";
        ticket->printTicket();
        
        std::cout << "\nThank you for using our ticketing system!\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}