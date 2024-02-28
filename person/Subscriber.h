#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "../subscription/Subscription.h"
#include "../subscription/SubscriptionPremium.h"
#include "Person.h"

class Subscriber : public Person {
    std::string phoneNumber;
    Subscription *subscription;

   public:
    Subscriber();
    Subscriber(int id, std::string name, std::string cnp, std::string phoneNumber, Subscription *subscription);
    Subscriber(const Subscriber &subscriber);
    ~Subscriber();

    void read(std::istream &is);
    void print(std::ostream &os);

    Subscriber &operator=(const Subscriber &subscriber);

    void setPhoneNumber(std::string phoneNumber);
    void setSubscription(Subscription *subscription);

    std::string getPhoneNumber();
    Subscription *getSubscription();
};

#endif