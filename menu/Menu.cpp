#include "Menu.h"

const std::string Menu::ADD_CLIENT = "ADD_CLIENT";
const std::string Menu::ADD_CLIENTS = "ADD_CLIENTS";
const std::string Menu::REMOVE_CLIENT = "REMOVE_CLIENT";
const std::string Menu::SHOW_CLIENTS = "SHOW_CLIENTS";
const std::string Menu::SHOW_PREMIUM = "SHOW_PREMIUM";
const std::string Menu::SHOW_PROFIT = "SHOW_PROFIT";
const std::string Menu::TEST_SUBSCRIPTIONS = "TEST_SUBSCRIPTIONS";
const std::string Menu::STOP = "STOP";

std::vector<std::string> Menu::getCommands() {
    std::vector<std::string> commands;
    commands.push_back(Menu::ADD_CLIENT);
    commands.push_back(Menu::ADD_CLIENTS);
    commands.push_back(Menu::REMOVE_CLIENT);
    commands.push_back(Menu::SHOW_CLIENTS);
    commands.push_back(Menu::SHOW_PREMIUM);
    commands.push_back(Menu::SHOW_PROFIT);
    commands.push_back(Menu::TEST_SUBSCRIPTIONS);
    commands.push_back(Menu::STOP);
    return commands;
}

void Menu::displayCommands() const {
    std::cout << std::endl;
    std::cout << Menu::ADD_CLIENT << " - adauga un client" << std::endl;
    std::cout << Menu::ADD_CLIENTS << " - adauga n clienti si stergei pe cei existenti" << std::endl;
    std::cout << Menu::REMOVE_CLIENT << " - sterge un client" << std::endl;
    std::cout << Menu::SHOW_CLIENTS << " - afiseaza clientii" << std::endl;
    std::cout << Menu::SHOW_PREMIUM << " - afiseaza numarul abonamentelor premium" << std::endl;
    std::cout << Menu::SHOW_PROFIT << " - afiseaza suma totala incasata" << std::endl;
    std::cout << Menu::TEST_SUBSCRIPTIONS << " - testeaza abonamentele" << std::endl;
    std::cout << Menu::STOP << " - opreste programul" << std::endl;
    std::cout << std::endl;
}

void Menu::run() {
    std::string command;
    while (true) {
        this->displayCommands();
        std::cin >> command;
        if (command == Menu::ADD_CLIENT) {
            Subscriber subscriber;
            std::cout << "Client " << clients.getSubscribers().size() + 1 << ": " << std::endl;
            std::cin >> subscriber;
            clients.addClient(subscriber);
        } else if (command == Menu::ADD_CLIENTS) {
            std::cin >> clients;
        } else if (command == Menu::REMOVE_CLIENT) {
            int x;
            std::cout << "Introdu numarul clientului pe care vrei sa il stergi: ";
            std::cin >> x;
            clients.deleteClient(x);
        } else if (command == Menu::SHOW_CLIENTS) {
            std::cout << clients;
        } else if (command == Menu::SHOW_PREMIUM) {
            std::cout << "Avem " << clients.getNumPremiumSubscriptions() << " abonamente premium" << std::endl;
        } else if (command == Menu::SHOW_PROFIT) {
            std::cout << "Suma totala incasata este de " << clients.getProfit() << " RON" << std::endl;
        } else if (command == Menu::STOP) {
            break;
        } else if (command == Menu::TEST_SUBSCRIPTIONS) {
            std::cout << "1 - Adauga abonamente\n2 - Adauga abonamente premium\n3 - Afiseaza abonamente\n4 - Afiseaza abonamente premium\n5 - Afiseaza abonamente premium fara discount\n";
            int option;
            std::cin >> option;
            switch (option) {
                case 1:
                    std::cin >> subscriptionManager1;
                    break;
                case 2:
                    std::cin >> subscriptionManager2;
                    break;
                case 3:
                    std::cout << subscriptionManager1;
                    break;
                case 4:
                    std::cout << subscriptionManager2;
                    break;
                case 5:
                    subscriptionManager2.printBaseSubscriptions();
                    break;
                default:
                    std::cout << "Optiune invalida\n";
                    break;
            }
        } else {
            std::cout << "Comanda invalida" << std::endl;
        }
    }
}
