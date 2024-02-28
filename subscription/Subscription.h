#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include <iostream>
#include <string>

class Subscription {
    std::string name;
    float price;
    int duration;

   public:
    Subscription();
    Subscription(std::string name, float price, int duration);
    Subscription(const Subscription &subscription);
    virtual ~Subscription();

    virtual void read(std::istream &is);
    virtual void print(std::ostream &os);

    Subscription &operator=(const Subscription &subscription);
    friend std::istream &operator>>(std::istream &is, Subscription &subscription);
    friend std::ostream &operator<<(std::ostream &os, Subscription &subscription);

    void setName(std::string name);
    void setPrice(float price);
    void setDuration(int duration);

    std::string getName();
    float getPrice();
    int getDuration();

    virtual float getTotalPrice();

    virtual Subscription *clone() const;
};

#endif