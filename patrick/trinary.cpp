/* trinary.cpp -- Read an input in trinary and print it in decimal
 * Copyright © 2015, Patrick M. Niedzielski <patrick@pniedzielski.net>
 *
 * Distributed under the Boost Software License, Version 1.0.  (See copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

int main() {
  using namespace std;

  auto trinary = ""s;
  cin >> trinary;

  auto value = 0;

  // size() returns an unsigned value, which we don't want to deal
  // with this early, so ignore it.
  auto place_value = static_cast<int>(trinary.size()) - 1;

  // Loop invariant: After the 𝒾th iteration of the loop, value is the
  // integer value of the inputted trinary number, but with all but
  // the first 𝒾 digits as 0.
  for (auto digit : trinary) {
    auto digit_value = 0;
    
         if (digit == '0') digit_value = 0;
    else if (digit == '1') digit_value = 1;
    else if (digit == '2') digit_value = 2;
    else {
      cerr << "Invalid trinary number\n"s;
      return EXIT_FAILURE;
    }

    value += digit_value * static_cast<int>(pow(3, place_value));
    --place_value;
  }

  cout << value << '\n';
}
