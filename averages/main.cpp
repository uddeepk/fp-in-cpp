/*
 * main.cpp
 * Averages
 * Uddeep Karki
 * May 1, 2021
 * Calculate average using functional programming. Example from book
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

double average_score(const std::vector<int> &scores);

int main() {
    std::cout << "Hello, World!" << std::endl;
    // creating test vector
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 1);
    std::cout << average_score(v);
    return 0;
}

double average_score(const std::vector<int> &scores) {
    //return std::accu
    return std::accumulate(
            scores.begin(), scores.end()
            , 0
            ) / static_cast <double> (scores.size());
}