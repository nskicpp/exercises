/* greeting.cpp -- Ask the user for their name and greet them
 * Copyright © 2015, Patrick M. Niedzielski <patrick@pniedzielski.net>
 *
 * Distributed under the Boost Software License, Version 1.0.  (See copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <string>
#include <cstdlib>

int main() {
  using namespace std;
  using namespace std::literals; // Inline namespace, not needed

  cout << "It's nice to meet you!  What's your name? "s;

  string name;
  getline(cin, name); // Read in the whole line

  if (name.empty()) {
      cout << "Fine, don't tell me your name.\n"s;
      return EXIT_FAILURE;
  }

  cout << "Hello, "s + name + "!\n"s;
}
  
  
