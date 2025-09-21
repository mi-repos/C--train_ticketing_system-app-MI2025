#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Station.h"

enum class TicketType {
    SINGLE,
    RETURN,
    DAY_PASS
};

class Ticket {
protected:
    Station source;
    Station destination;
    TicketType type;
    double fare;

public:
    Ticket(const Station& source, const Station& destination, TicketType type, double fare);
    virtual ~Ticket() = default;
    
    virtual void printTicket() const;
    
    Station getSource() const;
    Station getDestination() const;
    TicketType getType() const;
    double getFare() const;
};

class SingleTicket : public Ticket {
public:
    SingleTicket(const Station& source, const Station& destination, double fare);
    void printTicket() const override;
};

class ReturnTicket : public Ticket {
public:
    ReturnTicket(const Station& source, const Station& destination, double fare);
    void printTicket() const override;
};

class DayPass : public Ticket {
public:
    DayPass(const Station& source, const Station& destination, double fare);
    void printTicket() const override;
};

#endif // TICKET_H