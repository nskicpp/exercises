/*
 * poor_mans_cat.cpp - read STDIN and mirror it to STDOUT
 */
#include <iostream>
#include <cstdlib>

int main() {
    // Don't skip whitespace characters
    std::cin >> std::noskipws;

    auto input = ' ';

    while (std::cin >> input) {
        std::cout << input;
    }
}
