//
// Created by uddeepk on 5/1/21.
//

#include "Person.hpp"

Person::Person(const std::string& name, const std::string& gender): _name(name), _gender(_gender) {

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
