/* ternary.cpp

   Read a positive number in ternary from stdin.
   Whitespace has no significance.
   Print the number in decimal (displaying to the millionth place) to stdout.
   This could be easily done using `std::stoi`, but just for fun...

   This could likely be better written using other C++ features.
   However, to stick with the course, they will not be used.

   Example of how it works:
   102.11 --> [<1.0,0>, <0.0,1>, <2.0,2>, <1.0,-1>, <1.0,-2>]
   radix_point_pos = 3
   decimal_num = (1.0 * 3.0^(3-1-0)) + (0.0 * 3.0^(3-1-1)) +
                 (2.0 * 3.0^(3-1-2)) + (1.0 * 3.0^(-1)) +
                 (1.0 * 3.0^(-2))
               = 9.0 + 0.0 + 2.0 + (1.0/3.0) + (1.0/9.0)
               ~= 11.4444
*/

#include <cmath>    // pow
#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iomanip>  // setprecision
#include <iostream> // cin, cout, fixed
#include <string>
#include <tuple>
#include <vector>

int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Type a positive ternary number. Whitespace has no significance.\n"s
         << "When finished, press [ENTER] then [CTRL-D].\n"s;

    auto digit_tuples = vector<tuple<double, int>>{};

    auto exponent_index = 0;
    auto radix_point_pos = -1;

    // Loop invariant:
    // Before a '.' is read in:
    //   `radix_point_pos` -> -1
    //   `exponent_index`  -> current iteration count, starting with 0.
    // When a '.' is read in:
    //   `radix_point_pos` -> the current `exponent_index`. 
    //   `exponent_index`  -> -1
    // After that point:
    //   `radix_point_pos` stays constant.
    //   `exponent_index`  -> -1 * (current iteration count, starting with 1).
    //   If a character != '0' '1' or '2' is read in, exit with failure.
    auto digit = '_';
    while (cin >> digit) {
        auto digit_num = 0.;

        if (digit == '.') {
            if (radix_point_pos == -1) {
                radix_point_pos = exponent_index;
                exponent_index = -1;
                continue;
            } else {
                cerr << "\nERROR: Multiple radix points encountered.\n"s;
                return EXIT_FAILURE;
            }
        } else if (digit == '0') {
            digit_num = 0.0;
        } else if (digit == '1') {
            digit_num = 1.0;
        } else if (digit == '2') {
            digit_num = 2.0;
        } else {
            cerr << "\nERROR: <"s << digit << "> is an invalid character.\n"s;
            return EXIT_FAILURE;
        }

        digit_tuples.push_back(make_tuple(digit_num, exponent_index));

        if (radix_point_pos == -1) {
            ++exponent_index;
        } else {
            --exponent_index;
        }
    }

    if (digit_tuples.empty()) {
        cout << "Please enter a number!\n"s;
        return EXIT_FAILURE;
    }

    if (radix_point_pos < 0) {
        // No decimal from stdin, so consider it to be the last character.
        radix_point_pos = static_cast<int>(digit_tuples.size());
    }

    auto decimal_result = 0.0;

    // Loop invariant: `decimal_result` contains the value of creating the
    //  decimal representation of the values in `digit_tuples` up to that time.
    for (tuple<double, int> digit_tuple : digit_tuples) {
        auto digit_n = 0.;
        auto exponent_i = 0;
        tie(digit_n, exponent_i) = digit_tuple;

        auto power = 0.;
        if (exponent_i < 0) {
            power = static_cast<double>(exponent_i);
        } else {
            power = static_cast<double>(radix_point_pos - 1 - exponent_i);
        }

        decimal_result += digit_n * pow(3.0, power);
    }

    cout << "In decimal, it is ~"s
         << fixed << setprecision(4) // Show to the millionth place.
         << decimal_result
         << "\n"s;

    return EXIT_SUCCESS;
}
