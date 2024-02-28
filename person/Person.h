#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
    int id;
    std::string name;
    std::string cnp;

   public:
    Person();
    Person(int id, std::string name, std::string cnp);
    Person(const Person &person);
    virtual ~Person();

    virtual void read(std::istream &is);
    virtual void print(std::ostream &os);

    Person &operator=(const Person &person);
    friend std::istream &operator>>(std::istream &is, Person &person);
    friend std::ostream &operator<<(std::ostream &os, Person &person);

    void setId(int id);
    void setName(std::string name);
    void setCnp(std::string cnp);

    int getId();
    std::string getName();
    std::string getCnp();
};

#endif