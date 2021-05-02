#include <iostream>
#include <algorithm>

std::string trim_left(std::string s);
std::string trim_right(std::string s);
std::string trim(std::string s);
/*auto is_not_space = [] (std::string::iterator it) {
    return !std::isspace(*it);
};*/
bool is_not_space (const char c) {
    return !std::isspace(c);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::isspace('c');
    return 0;
}

std::string trim_left(std::string s) {
    s.erase(s.begin(),
                   std::find_if(s.begin(), s.end(), is_not_space )) ; /*[] (std::string::iterator it) {
                    return std::isspace(*it);
                   }; )); */
    return s;
}

std::string trim_right(std::string s) {
    s.erase( std::find_if(s.rbegin(), s.rend(), is_not_space).base(),
             s.end());
    return s;
}

std::string trim(std::string s) {
    return trim_left(trim_right(std::move(s)));
}