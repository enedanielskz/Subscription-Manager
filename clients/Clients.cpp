#include "Clients.h"

Clients::Clients() {}

Clients::Clients(std::vector<Subscriber> subscribers) { this->subscribers = subscribers; }

Clients::Clients(const Clients &clients) { this->subscribers = clients.subscribers; }

Clients::~Clients() {}

Clients &Clients::operator=(const Clients &clients) {
    this->subscribers = clients.subscribers;

    return *this;
}

std::istream &operator>>(std::istream &is, Clients &clients) {
    clients.subscribers.clear();
    std::cout << "Introduceti numarul de clienti pe care vreti sa il cititi: ";
    int n;
    is >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Client " << i + 1 << ":" << std::endl;
        Subscriber subscriber;
        is >> subscriber;
        clients.subscribers.push_back(subscriber);
        std::cout << std::endl;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Clients &clients) {
    os << "Avem " << clients.subscribers.size() << " clienti:" << std::endl;
    for (int i = 0; i < clients.subscribers.size(); i++) {
        os << "Client " << i + 1 << ":" << std::endl;
        os << clients.subscribers[i];
        os << std::endl;
    }

    return os;
}

void Clients::setSubscribers(std::vector<Subscriber> subscribers) { this->subscribers = subscribers; }
std::vector<Subscriber> Clients::getSubscribers() { return this->subscribers; }

void Clients::addClient(Subscriber subscriber) { this->subscribers.push_back(subscriber); }
void Clients::deleteClient(int clientNumber) {
    try {
        if (clientNumber <= 0 || clientNumber > this->subscribers.size()) {
            throw std::out_of_range("Eroare: Numarul clientului nu este valid.");
        }
        this->subscribers.erase(this->subscribers.begin() + clientNumber - 1);
    } catch (const std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
}

int Clients::getNumPremiumSubscriptions() {
    int cnt = 0;
    for (int i = 0; i < this->subscribers.size(); i++) {
        if (dynamic_cast<SubscriptionPremium *>(this->subscribers[i].getSubscription()) != nullptr) {
            cnt++;
        }
    }

    return cnt;
}

float Clients::getProfit() {
    float sum = 0;
    for (int i = 0; i < this->subscribers.size(); i++) {
        sum += this->subscribers[i].getSubscription()->getTotalPrice();
    }

    return sum;
}
