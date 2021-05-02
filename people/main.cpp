#include <iostream>
#include <vector>
#include <algorithm>
#include "Person.hpp"

using std::vector;
using std::string;

vector <Person> vecPeople () ;
vector <string> getFemale (vector <Person> v);

void print (const vector <Person> &v);
void print (const vector <string> &v);

int main() {
    std::cout << "Hello, World!" << std::endl;


//    vector <Person> people ;
    //Person p1 {"ss", "gg"};
    auto people = vecPeople();
    print (people);

    // get female
    auto vecFemaleNames = getFemale(people);

    std::cout << "\nFemales filetered";
    print(vecFemaleNames);
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

vector<string> getFemale(vector<Person> v) {
    // Filter female
    auto it = std::partition(std::begin(v), std::end(v), [](Person p) {
        return p.getGender() == "female";
    });
    v.erase(it, v.end());
    // Transform to names
    vector <string> vecNames;// (v.size());

    std::transform(std::begin(v), std::end(v), std::back_inserter(vecNames), [] (Person p) {
        return p.getName();
    });
    return vecNames;
}

void print(const vector<Person> &v) {
    for( const auto &x : v) {
        std::cout << x.getName() << " " << x.getGender() << "\n";
    }
}

void print(const vector<string> &v) {
    for ( const auto &x : v) {
        std::cout << x << "\n";
    }
}
