#ifndef SUBSCRIPTIONMANAGER_H
#define SUBSCRIPTIONMANAGER_H

#include <iostream>
#include <vector>

#include "SubscriptionPremium.h"

template <typename T>
class SubscriptionManager {
    std::vector<T> subscriptions;

   public:
    SubscriptionManager() {}
    ~SubscriptionManager() {}

    SubscriptionManager(std::vector<T> subscriptions) {
        this->subscriptions = subscriptions;
    }

    SubscriptionManager(const SubscriptionManager<T>& subscriptionManager) {
        this->subscriptions = subscriptionManager.subscriptions;
    }

    SubscriptionManager<T>& operator=(const SubscriptionManager<T>& subscriptionManager) {
        this->subscriptions = subscriptionManager.subscriptions;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, SubscriptionManager<T>& subscriptionManager) {
        os << "Avem " << subscriptionManager.subscriptions.size() << " abonamente:" << std::endl;
        for (int i = 0; i < subscriptionManager.subscriptions.size(); i++) {
            os << "Abonament " << i + 1 << ":" << std::endl;
            os << subscriptionManager.subscriptions[i];
            os << std::endl;
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is, SubscriptionManager<T>& subscriptionManager) {
        std::cout << "Introdu numarul de abonamente pe care vrei sa le citesti: ";
        int n;
        is >> n;
        for (int i = 0; i < n; i++) {
            std::cout << "Abonament " << i + 1 << ":" << std::endl;
            T subscription;
            is >> subscription;
            subscriptionManager.subscriptions.push_back(subscription);
        }
        return is;
    }
};

template <>
class SubscriptionManager<SubscriptionPremium> {
    std::vector<SubscriptionPremium> subscriptions;

   public:
    SubscriptionManager() {}
    ~SubscriptionManager() {}

    SubscriptionManager(std::vector<SubscriptionPremium> subscriptions) {
        this->subscriptions = subscriptions;
    }

    SubscriptionManager(const SubscriptionManager<SubscriptionPremium>& subscriptionManager) {
        this->subscriptions = subscriptionManager.subscriptions;
    }

    SubscriptionManager<SubscriptionPremium>& operator=(const SubscriptionManager<SubscriptionPremium>& subscriptionManager) {
        this->subscriptions = subscriptionManager.subscriptions;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, SubscriptionManager<SubscriptionPremium>& subscriptionManager) {
        os << "Avem " << subscriptionManager.subscriptions.size() << " abonamente premium:" << std::endl;
        for (int i = 0; i < subscriptionManager.subscriptions.size(); i++) {
            os << "Abonament premium " << i + 1 << ":" << std::endl;
            os << subscriptionManager.subscriptions[i];
            os << std::endl;
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is, SubscriptionManager<SubscriptionPremium>& subscriptionManager) {
        std::cout << "Introdu numarul de abonamente premium pe care vrei sa le citesti: ";
        int n;
        is >> n;
        for (int i = 0; i < n; i++) {
            std::cout << "Abonament premium " << i + 1 << ":" << std::endl;
            SubscriptionPremium subscription;
            is >> subscription;
            subscriptionManager.subscriptions.push_back(subscription);
        }
        return is;
    }

    void printBaseSubscriptions() {
        std::cout << "Abonamente premium (fara discount):" << std::endl;
        for (int i = 0; i < this->subscriptions.size(); i++) {
            std::cout << "Abonament premium " << i + 1 << ":" << std::endl;
            Subscription baseSubscription = static_cast<Subscription>(subscriptions[i]);
            std::cout << baseSubscription << std::endl;
        }
    }
};

#endif
