#include <iostream>
#include <map>

/**
 * @brief *  C++ Example - Update value in map
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv) {
    std::map<int, std::string> m;

    /* Insert some elements ( key value pair) in the hash map */
    m.insert(std::pair<int, std::string>(1, "Hi"));
    m.insert(std::pair<int, std::string>(2, "how"));
    m.insert(std::pair<int, std::string>(3, "are"));
    m.insert(std::pair<int, std::string>(4, "you"));

    for (auto elem : m) {
        std::cout << elem.first << " - " << elem.second << std::endl;
    }

    m.insert(std::pair<int, std::string>(1, "bye"));

    for (auto elem : m) {
        std::cout << elem.first << " - " << elem.second << std::endl;
    }
}