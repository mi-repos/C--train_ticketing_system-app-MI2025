#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>
#include "../core/Station.h"
#include "../core/Ticket.h"

class InputHandler {
public:
    static std::string getStringInput(const std::string& prompt);
    static int getIntInput(const std::string& prompt, int min, int max);
    static Station selectStation(const std::vector<Station>& stations, const std::string& prompt);
    static TicketType selectTicketType();
};

#endif // INPUTHANDLER_H