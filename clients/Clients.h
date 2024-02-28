#ifndef CLIENTS_H
#define CLIENTS_H

#include <vector>

#include "../person/Subscriber.h"

class Clients {
    std::vector<Subscriber> subscribers;

   public:
    Clients();
    Clients(std::vector<Subscriber> subscribers);
    Clients(const Clients &clients);
    ~Clients();

    Clients &operator=(const Clients &clients);
    friend std::istream &operator>>(std::istream &is, Clients &clients);
    friend std::ostream &operator<<(std::ostream &os, Clients &clients);

    void setSubscribers(std::vector<Subscriber> subscribers);
    std::vector<Subscriber> getSubscribers();

    void addClient(Subscriber subscriber);
    void deleteClient(int clientNumber);

    int getNumPremiumSubscriptions();
    float getProfit();
};

#endif