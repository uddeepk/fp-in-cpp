#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include "Person.hpp"

using std::vector;
using std::string;

vector <Person> vecPeople () ;
vector <string> getFemale (vector <Person> v);
bool is_female(const Person &p);
bool is_not_female(const Person &p);
string name(const Person &p);

template <typename FilterFunction>
vector <string> names_for ( const vector<Person> &v, FilterFunction filter) {

    vector <Person> chosenPeople;

    std::copy_if(v.cbegin(), v.cend(), std::back_inserter(chosenPeople),
                 filter);

    vector <string> names(chosenPeople.size());

    std::transform(chosenPeople.cbegin(), chosenPeople.cend(),
                   names.begin(),
                   name);
    return names;

}

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

    std::cout << "\nFemales filetered\n";
    print(vecFemaleNames);

    std::cout << "\nUsing template for function\n";
    auto vecMales = names_for(people, is_not_female);
    print(vecMales);
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
    /*
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
    */

    /* // other version
    v.erase(
            std::remove_if(v.begin(), v.end(), is_not_female),
            v.end()
            );
    vector <string > names(v.size()) ;

    std::transform(v.begin(), v.end(), names.begin(), name);
    return names;
     */


    vector <Person> females;

    std::copy_if(v.cbegin(), v.cend(), std::back_inserter(females),
                 is_female);

    vector <string> names(females.size());

    std::transform(females.cbegin(), females.cend(),
                   names.begin(),
                   name);
    return names;


    //return v | std::ranges::views::filter( is_female) | std::ranges::views::transform(name);
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

bool is_not_female(const Person &p) {
    return !is_female(p);
}

bool is_female(const Person &p) {
    return p.getGender() == "female";
}

string name(const Person &p) {
    return p.getName();
}
