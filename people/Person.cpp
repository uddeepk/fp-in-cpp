//
// Created by uddeepk on 5/1/21.
//

#include "Person.hpp"
#include <iostream>

Person::Person():_name(""), _gender("") {
//    std::cout << "Blank Person Created\n";
}

Person::Person(const std::string& name, const std::string& gender): _name(name), _gender(gender) {
//    std::cout << "Person with name " << _name << " and gender " << _gender << " created! \n";
}

Person::Person(const Person &p):_name(p.getName()), _gender(p.getGender()) {
//    std::cout << "Person with name " << _name << " and gender " << _gender << " copied! \n";

}

void Person::setName(const std::string &newName) {
    _name = newName;
}

std::string Person::getName() const {
    return _name;
}

void Person::setGender(const std::string &newGender) {
    _gender = newGender;
}

std::string Person::getGender() const {
    return _gender;
}

Person::~Person() {
//    std::cout << "Person with name " << _name << " and gender " << _gender << " destroyed! \n";

}