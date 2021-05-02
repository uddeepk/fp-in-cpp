//
// Created by uddeepk on 5/1/21.
//

#ifndef PEOPLE_PERSON_HPP
#define PEOPLE_PERSON_HPP

//#include <string>
#include <iostream>

class Person {
public:
    // Constructor
    Person();
    Person(const std::string& name, const std::string& gender);
    Person(const Person &p);

    //Dtor
    ~Person();
    // Getters and Setters
    void setName(const std::string &newName);
    std::string getName () const;
    void setGender(const std::string &newGender);
    std::string getGender() const;

private:
    std::string _name;
    std::string _gender;

};


#endif //PEOPLE_PERSON_HPP
