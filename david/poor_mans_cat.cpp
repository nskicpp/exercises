/*
 * poor_mans_cat.cpp - read STDIN and mirror it to STDOUT
 */
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    // Don't skip whitespace characters
    std::cin >> std::noskipws;

    char input;
    std::cin >> input;
    while (std::cin) {
        std::cout << input;
        std::cin >> input;
    }
    return EXIT_SUCCESS;
}
