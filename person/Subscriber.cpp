#include "Subscriber.h"

Subscriber::Subscriber() {
    this->subscription = nullptr;
}

Subscriber::Subscriber(int id, std::string nume, std::string cnp, std::string phoneNumber, Subscription *subscription)
    : Person(id, nume, cnp) {
    this->phoneNumber = phoneNumber;
    this->subscription = subscription;
}

Subscriber::Subscriber(const Subscriber &subscriber)
    : Person(subscriber) {
    this->phoneNumber = subscriber.phoneNumber;
    this->subscription = subscriber.subscription->clone();
}

Subscriber::~Subscriber() {
    delete this->subscription;
}

Subscriber &Subscriber::operator=(const Subscriber &subscriber) {
    Person::operator=(subscriber);
    this->phoneNumber = subscriber.phoneNumber;
    delete this->subscription;
    this->subscription = subscriber.subscription->clone();

    return *this;
}

void Subscriber::read(std::istream &is) {
    Person::read(is);

    std::cout << "Introduceti numarul de telefon al abonatului: ";
    is >> this->phoneNumber;

    if (this->subscription != nullptr) {
        delete this->subscription;
    }

    std::cout << "Abonament premium? (Y/N): ";
    char premium;
    is >> premium;
    if (premium == 'Y') {
        this->subscription = new SubscriptionPremium();
    } else {
        this->subscription = new Subscription();
    }
    is >> *(this->subscription);
}

void Subscriber::print(std::ostream &os) {
    Person::print(os);

    os << "Numarul de telefon al abonatului: " << this->phoneNumber << std::endl;
    os << *(this->subscription);
}

void Subscriber::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Subscriber::setSubscription(Subscription *subscription) {
    if (this->subscription != nullptr) {
        delete this->subscription;
    }
    this->subscription = subscription;
}

std::string Subscriber::getPhoneNumber() { return this->phoneNumber; }
Subscription *Subscriber::getSubscription() { return this->subscription; }
