/* prime_factors.cpp

   Read a positive number from stdin.
   Print out the unique prime factors of that number.
   Does a naive implementation. For 982451653, takes a few seconds.
*/

#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // cin, cout
#include <string>
#include <tuple>
#include <vector>

int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Enter a single integer > 1, then press [ENTER]:\n"s;

    long num;
    cin >> num;

    if (num < 2) {
        cerr << "ERROR: input must be a number > 1.\n"s;
        return EXIT_FAILURE;
    }

    auto prime_factors = vector<long>{};

    if (num % 2 == 0) {
        prime_factors.push_back(2);
    }
    auto factor_to_try = 3;

    // Loop invariant: \forall x, 3 <= x < `factor_to_try`, if `x` is a 
    // unique prime factor of the number, it has been added to the
    // `prime_factors` vector.
    while (factor_to_try <= num) {
        if (num % factor_to_try == 0) {
            auto add = true;
            for (auto prime_factor : prime_factors) { 
                if (factor_to_try % prime_factor == 0) {
                    add = false;
                    break;
                }
            }
            if (add) {
                num /= factor_to_try;
                prime_factors.push_back(factor_to_try);
            }
        }
        factor_to_try += 2;
    }

    if (prime_factors.empty()) {
        cout << "There were no prime factors."s;
    } else {
        cout << "Unique prime factor(s): "s;
        for (auto prime_factor : prime_factors) {
            cout << prime_factor << " "s;
        }
    }
    cout << "\n"s;

    return EXIT_FAILURE;
}
