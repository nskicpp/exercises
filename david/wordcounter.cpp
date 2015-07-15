/*
 * wordcounter.cpp - count the number of words in STDIN
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std::literals;

int main() {
    auto input = ""s;
    auto words = 0;

    while (std::cin >> input) {
        ++words;
    }
    std::cout << words;
    return EXIT_SUCCESS;
}
