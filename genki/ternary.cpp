/* ternary.cpp

   Read a positive number in ternary from stdin. Whitespace-terminated.
   Print the number in decimal to stdout.
*/

#include <cmath>    // pow
#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // cin, cout
#include <string>

int main() {
    using namespace std;
    using namespace std::literals; // ""s

    auto input = ""s;
    cin >> input;

    auto result = 0.0;
    auto has_seen_radix = false;
    auto negative_index = 1.0;

    // Loop invariant: Every digit before this has been evaluted in its value
    // and position of the input and that value has been added to `result`.
    for (auto digit : input) {
        if (digit == '.') {
            if (!has_seen_radix) {
                has_seen_radix = true;
                continue;
            } else {
                cerr << "ERROR: Multiple radix points encountered.\n"s;
                return EXIT_FAILURE;
            }
        } else if (digit == '0') {
            if (!has_seen_radix) {
                result *= 3.0;
            }
        } else if (digit == '1') {
            if (has_seen_radix) {
                result += 1.0 / pow(3.0, negative_index);
            } else {
                result *= 3.0;
                result += 1.0;
            }
        } else if (digit == '2') {
            if (has_seen_radix) {
                result += 2.0 / pow(3.0, negative_index);
            } else {
                result *= 3.0;
                result += 2.0;
            }
        } else {
            cerr << "ERROR: <"s << digit << "> is an invalid character.\n"s;
            return EXIT_FAILURE;
        }
        if (has_seen_radix) {
            negative_index += 1.0;
        }
    }

    cout << result << "\n"s;

    return EXIT_SUCCESS;
}
