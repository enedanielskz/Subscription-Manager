#ifndef SUBSCRIPTIONPREMIUM_H
#define SUBSCRIPTIONPREMIUM_H

#include "Subscription.h"

class SubscriptionPremium : public Subscription {
    int discount;

   public:
    SubscriptionPremium();
    SubscriptionPremium(std::string name, float price, int duration, int discount);
    SubscriptionPremium(const SubscriptionPremium &subscriptionPremium);
    ~SubscriptionPremium();

    void read(std::istream &is);
    void print(std::ostream &os);

    SubscriptionPremium &operator=(const SubscriptionPremium &subscriptionPremium);

    void setDiscount(int discount);
    int getDiscount();

    float getTotalPrice();

    SubscriptionPremium *clone() const;
};

#endif