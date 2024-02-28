#include "Person.h"

Person::Person() {}

Person::Person(int id, std::string name, std::string cnp) {
    this->id = id;
    this->name = name;
    this->cnp = cnp;
}

Person::Person(const Person &person) {
    this->id = person.id;
    this->name = person.name;
    this->cnp = person.cnp;
}

Person::~Person() {}

Person &Person::operator=(const Person &person) {
    this->id = person.id;
    this->name = person.name;
    this->cnp = person.cnp;

    return *this;
}

void Person::read(std::istream &is) {
    std::cout << "Introduceti id-ul persoanei: ";
    is >> this->id;
    std::cout << "Introduceti numele persoanei: ";
    is >> this->name;
    std::cout << "Introduceti cnp-ul persoanei: ";
    is >> this->cnp;
}

void Person::print(std::ostream &os) {
    os << "Id-ul persoanei: " << this->id << std::endl;
    os << "Numele persoanei: " << this->name << std::endl;
    os << "Cnp-ul persoanei: " << this->cnp << std::endl;
}

std::istream &operator>>(std::istream &is, Person &person) {
    person.read(is);

    return is;
}

std::ostream &operator<<(std::ostream &os, Person &person) {
    person.print(os);

    return os;
}

void Person::setId(int id) { this->id = id; }
void Person::setName(std::string name) { this->name = name; }
void Person::setCnp(std::string cnp) { this->cnp = cnp; }

int Person::getId() { return this->id; }
std::string Person::getName() { return this->name; }
std::string Person::getCnp() { return this->cnp; }
