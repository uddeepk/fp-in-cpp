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
double scores_product(const std::vector<int> &scores);

int main() {
    std::cout << "Hello, World!" << std::endl;
    // creating test vector
    std::vector<int> v(5);
    std::iota(v.begin(), v.end(), 1);
    std::cout << average_score(v) << "\n";
    std::cout << scores_product(v) << "\n";
    return 0;
}

double average_score(const std::vector<int>& scores) {
    //return std::accu
    return std::accumulate(
            scores.cbegin(), scores.cend(),
            0
            ) / static_cast <double> (scores.size());
}

double scores_product(const std::vector<int>& scores) {
    return std::accumulate(
            scores.cbegin(), scores.cend(),
            1,
            std::multiplies()
            );
}