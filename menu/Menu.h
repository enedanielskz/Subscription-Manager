#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

#include "../clients/Clients.h"
#include "../subscription/SubscriptionManager.h"

class Menu {
    static const std::string ADD_CLIENT;
    static const std::string ADD_CLIENTS;
    static const std::string REMOVE_CLIENT;
    static const std::string SHOW_CLIENTS;
    static const std::string SHOW_PREMIUM;
    static const std::string SHOW_PROFIT;
    static const std::string TEST_SUBSCRIPTIONS;
    static const std::string STOP;

    Clients clients;
    SubscriptionManager<Subscription> subscriptionManager1;
    SubscriptionManager<SubscriptionPremium> subscriptionManager2;

    void displayCommands() const;

   public:
    static std::vector<std::string> getCommands();
    void run();
};

#endif