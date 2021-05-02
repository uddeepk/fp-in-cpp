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
int count_lines(const std::string& s);
int f(int previous_count, char c);

int main() {
    std::cout << "Hello, World!" << std::endl;
    // creating test vector
    std::vector<int> v(5);
    std::iota(v.begin(), v.end(), 1);
    std::cout << average_score(v) << "\n";
    std::cout << scores_product(v) << "\n";
    std::cout << count_lines("h\ns\ntest\n4\n") << "\n";
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

// Counting newlines using std::accumulate
int count_lines(const std::string &s) {
    return std::accumulate(
            s.cbegin(), s.cend(),
            0,
            f
            );
}

int f(int previous_count, char c) { // (int, char) -> int
    return (c != '\n' ? previous_count : previous_count + 1);
}
