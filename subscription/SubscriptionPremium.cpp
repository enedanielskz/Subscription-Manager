#include "SubscriptionPremium.h"

SubscriptionPremium::SubscriptionPremium() {}

SubscriptionPremium::SubscriptionPremium(std::string name, float price, int duration, int discount)
    : Subscription(name, price, discount) {
    this->discount = discount;
}

SubscriptionPremium::SubscriptionPremium(const SubscriptionPremium &subscriptionPremium)
    : Subscription(subscriptionPremium) {
    this->discount = subscriptionPremium.discount;
}

SubscriptionPremium::~SubscriptionPremium() {}

SubscriptionPremium &SubscriptionPremium::operator=(const SubscriptionPremium &subscriptionPremium) {
    Subscription::operator=(subscriptionPremium);
    this->discount = subscriptionPremium.discount;

    return *this;
}

void SubscriptionPremium::read(std::istream &is) {
    Subscription::read(is);
    std::cout << "Introduceti discount-ul abonamentului: ";
    is >> this->discount;
}

void SubscriptionPremium::print(std::ostream &os) {
    Subscription::print(os);
    os << "Discount-ul abonamentului: " << this->discount << std::endl;
}

std::istream &operator>>(std::istream &is, SubscriptionPremium &subscriptionPremium) {
    subscriptionPremium.read(is);

    return is;
}

std::ostream &operator<<(std::ostream &os, SubscriptionPremium &subscriptionPremium) {
    subscriptionPremium.print(os);

    return os;
}

void SubscriptionPremium::setDiscount(int discount) { this->discount = discount; }
int SubscriptionPremium::getDiscount() { return this->discount; }

float SubscriptionPremium::getTotalPrice() {
    float initialPrice = Subscription::getTotalPrice();
    float finalPrice = initialPrice - initialPrice * (float(discount) / 100);

    return finalPrice;
}

SubscriptionPremium *SubscriptionPremium::clone() const {
    return new SubscriptionPremium(*this);
}
