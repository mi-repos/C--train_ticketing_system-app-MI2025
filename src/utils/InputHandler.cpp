#include "InputHandler.h"
#include <iostream>
#include <limits>

std::string InputHandler::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

int InputHandler::getIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
    }
}

Station InputHandler::selectStation(const std::vector<Station>& stations, const std::string& prompt) {
    std::cout << prompt << "\n";
    for (size_t i = 0; i < stations.size(); ++i) {
        std::cout << i + 1 << ". " << stations[i].getName() 
                  << " (Zone " << stations[i].getZone() << ")\n";
    }
    
    int choice = getIntInput("Enter station number: ", 1, stations.size());
    return stations[choice - 1];
}

TicketType InputHandler::selectTicketType() {
    std::cout << "\nSelect Ticket Type:\n";
    std::cout << "1. Single Journey\n";
    std::cout << "2. Return Journey\n";
    std::cout << "3. Day Pass\n";
    
    int choice = getIntInput("Enter ticket type (1-3): ", 1, 3);
    
    switch (choice) {
        case 1: return TicketType::SINGLE;
        case 2: return TicketType::RETURN;
        case 3: return TicketType::DAY_PASS;
        default: return TicketType::SINGLE;
    }
}