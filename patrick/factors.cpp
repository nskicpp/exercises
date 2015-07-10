/* factors.cpp -- Print the prime factors of a number
 * Copyright © 2015, Patrick M. Niedzielski <patrick@pniedzielski.net>
 *
 * Distributed under the Boost Software License, Version 1.0.  (See copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <cmath>

int main() {
  using namespace std;

  auto n = 0;
  cin >> n;

  // Loop invariant: All prime factors under potential_factor have been printed.
  for (auto potential_factor = 2; potential_factor <= n; ++potential_factor) {
    bool is_prime = true;

    // Loop invariant: is_prime represents whether the potential_factor is not
    // divisible by any numbers checked so far.
    for (auto i = 2; is_prime && i <= sqrt(potential_factor); ++i) {
      // You can also write this with a continue statement.
      if (potential_factor % i == 0)
        is_prime = false;
    }

    if (is_prime && n % potential_factor == 0)
      cout << potential_factor << ' ';
  }
  cout << '\n';
}
