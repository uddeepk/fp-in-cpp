#include <iostream>
#include <vector>
#include "Person.hpp"

using std::vector;
using std::string;

vector <Person> vecPeople () ;

int main() {
    std::cout << "Hello, World!" << std::endl;


//    vector <Person> people ;
    //Person p1 {"ss", "gg"};
    auto people = vecPeople();
    return 0;
}

vector <Person> vecPeople() {
    vector <vector <string>> people = {
            {"Paul",     "male"},
            {"Veronica", "female"},
            {"Robert",   "male"},
            {"Theresa",   "female"},
            {"Theodore", "male"},
            {"Angie",    "female"}
    };
    vector <Person> v;

    for ( const auto &p : people) {
        v.push_back(Person(p[0], p[1]));
    }

    return v;
}