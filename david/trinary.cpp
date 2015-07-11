/*
 * trinary.cpp - convert a trinary number from STDIN to a decimal number
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std::literals;

int main() {
    // Don't skip whitespace so we can handle it appropriately
    std::cin >> std::noskipws;

    auto character = '0';
    auto result = 0;
    auto hasReadDigit = false;

    std::cin >> character;
    while (std::cin) {
        if (character == '0') {
            hasReadDigit = true;
            result *= 3;
        }
        else if (character == '1') {
            hasReadDigit = true;
            result *= 3;
            result += 1;
        }
        else if (character == '2') {
            hasReadDigit = true;
            result *= 3;
            result += 2;
        }
        else if (character == '\n') {
            // Stop reading when a newline is encountered
            break;
        }
        else if (hasReadDigit || character != ' ') {
            // Give an error if they enter non-space before any characters,
            // or non-digit-or-newline after any characters
            std::cout << "Invalid trinary character: "s << character;
            return EXIT_FAILURE;
        }
        std::cin >> character;
    }

    if (hasReadDigit) {
        std::cout << result;
        return EXIT_SUCCESS;
    }
    else {
        std::cout << "No digits read.\n"s;
        return EXIT_FAILURE;
    }
}
