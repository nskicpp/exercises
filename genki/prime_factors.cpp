/* prime_factors.cpp

   Read a positive number from stdin.
   Print out the unique prime factors of that number.
   Does a naive implementation. For example, 982451653 (prime) takes a sec.
*/

#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // cin, cout
#include <string>
#include <vector>

int main() {
    using namespace std;
    using namespace std::literals; // ""s

    auto num = 0;
    cin >> num;

    if (!(num > 1)) {
        cerr << "ERROR: input must be a number > 1.\n"s;
        return EXIT_FAILURE;
    }

    auto prime_factors = vector<int>{};

    if (num % 2 == 0) {
        prime_factors.push_back(2);
    }

    // Loop invariant: \forall x, 3 <= x < `factor_to_try`, if `x` is a 
    // unique prime factor of the number, it has been added to `prime_factors`.
    auto factor_to_try = 3;
    while (factor_to_try <= num) {
        if (num % factor_to_try == 0) {
            auto is_prime_factor = true;
            for (auto prime_factor : prime_factors) { 
                if (factor_to_try % prime_factor == 0) {
                    is_prime_factor = false;
                    break;
                }
            }
            if (is_prime_factor) {
                num /= factor_to_try;
                prime_factors.push_back(factor_to_try);
            }
        }
        factor_to_try += 2;
    }

    for (auto prime_factor : prime_factors) {
        cout << prime_factor << " "s;
    }
    cout << "\n"s;

    return EXIT_SUCCESS;
}
