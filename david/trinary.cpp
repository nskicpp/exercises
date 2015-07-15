/*
 * trinary.cpp - convert a trinary number from STDIN to a decimal number.
 *
 * A valid trinary number is any number of whitespace characters, followed
 * by any number of digits 0, 1, or 2 (so long as the resulting trinary
 * number fits in a signed int), followed by EOF or any number of whitespace
 * characters. Any additional input afterwards is ignored; any input
 * otherwise is an error.
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std::literals;

int main() {
    auto input = ""s;
    if (std::cin >> input) {
        auto result = 0;
        for (auto c : input) {
            if (c == '0') {
                result *= 3;
            }
            else if (c == '1') {
                result *= 3;
                result += 1;
            }
            else if (c == '2') {
                result *= 3;
                result += 2;
            }
            else {
                std::cerr << "Invalid trinary digit: "s << c << std::endl;
                return EXIT_FAILURE;
            }
        }
        std::cout << result;
        return EXIT_SUCCESS;
    }
    else {
        std::cerr << "No digits read.\n"s;
        return EXIT_FAILURE;
    }
}
