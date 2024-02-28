#include "Subscription.h"

Subscription::Subscription() {}

Subscription::Subscription(std::string name, float price, int duration) {
    this->name = name;
    this->price = price;
    this->duration = duration;
}

Subscription::Subscription(const Subscription &subscription) {
    this->name = subscription.name;
    this->price = subscription.price;
    this->duration = subscription.duration;
}

Subscription::~Subscription() {}

Subscription &Subscription::operator=(const Subscription &subscription) {
    this->name = subscription.name;
    this->price = subscription.price;
    this->duration = subscription.duration;

    return *this;
}

void Subscription::read(std::istream &is) {
    std::cout << "Introduceti numele abonamentului: ";
    is >> this->name;
    std::cout << "Introduceti pretul abonamentului: ";
    is >> this->price;
    std::cout << "Introduceti durata abonamentului: ";
    is >> this->duration;
}

void Subscription::print(std::ostream &os) {
    os << "Numele abonamentului: " << this->name << std::endl;
    os << "Pretul abonamentului: " << this->price << std::endl;
    os << "Durata abonamentului: " << this->duration << std::endl;
}

std::istream &operator>>(std::istream &is, Subscription &subscription) {
    subscription.read(is);

    return is;
}

std::ostream &operator<<(std::ostream &os, Subscription &subscription) {
    subscription.print(os);

    return os;
}

void Subscription::setName(std::string name) { this->name = name; }
void Subscription::setPrice(float prince) { this->price = price; }
void Subscription::setDuration(int duration) { this->duration = duration; }

std::string Subscription::getName() { return this->name; }
float Subscription::getPrice() { return this->price; }
int Subscription::getDuration() { return this->duration; }

float Subscription::getTotalPrice() { return this->price * this->duration; }

Subscription *Subscription::clone() const {
    return new Subscription(*this);
}
