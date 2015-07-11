/*
 * wordcounter.cpp - count the number of words in STDIN
 */
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string input;
    auto words = 0;

    std::cin >> input;
    while (std::cin) {
        std::cin >> input;
        ++words;
    }
    std::cout << words;
    return EXIT_SUCCESS;
}
