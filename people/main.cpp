#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
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

//template <typename FilterFunction>
//std::vector<std::string> names_for_naiverec( const std::vector<Person> &people,
//                                             FilterFunction filter)
//{
//    if (people.empty()) {
//        return {};
//
//    } else {
//        const auto head = people.front();
//        const auto processed_tail = names_for_naiverec(
//                /*tail(people)*/ std::vector(people.begin()+1, people.end()) ,
//                filter);
//
//        if (filter (head)) {
//            std::vector<std::string>
//            processed_tail.insert(processed_tail.begin(), head.getName());
//            return processed_tail;
//        } else {
//            return processed_tail;
//        }
//    }
//}

template <typename FilterFunction, typename Iterator>
std::vector<std::string> names_for_helper(
        Iterator people_begin,
        Iterator people_end,
        FilterFunction filter,
        std::vector<std::string> previously_collected)
{
    if (people_begin == people_end) {
        return previously_collected;
    } else {
        const auto head = *people_begin;

        if (filter (head)) {
            previously_collected.push_back(name(head));
        }

        return names_for_helper(
                people_begin + 1,
                people_end,
                filter,
                std::move(previously_collected));
    }
}

template <typename FilterFunction, typename Iterator>
std::vector <std::string> names_for_tail (
        Iterator people_begin,
        Iterator people_end,
        FilterFunction filter)
{
    return names_for_helper(people_begin, people_end, filter, {});
}

//template <typename FilterFunction>
//std::vector<std::string> append_name_if (
//        std::vector<std::string> previously_collected,
//        const Person &person)
//{
//    if (filter (person)) {
//        previously_collected.push_back(name(person));
//    }
//    return previously_collected;
//}


template <typename FilterFunction>
std::vector <std::string> names_for_fold (
        const vector <Person> people,
        FilterFunction filter)
{
    auto append_name_if  = [=]  (
            std::vector<std::string> previously_collected,
            const Person &person)
    {
        if (filter (person)) {
            previously_collected.push_back(name(person));
        }
        return previously_collected;
    };
    return std::accumulate(people.cbegin(), people.cend(), std::vector<std::string> {}, append_name_if);
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

    std::cout <<"\nTail Call\n";
    auto vecFemalesX = names_for_tail(people.begin(), people.end(), is_female);
    print (vecFemalesX);

    std::cout << "\nUsing std::accumulate\n";
    auto vecMalesY = names_for_fold(people, is_not_female);
    print(vecMalesY);
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
