/* cat.cpp -- Echo stdin to stdout
 * Copyright © 2015, Patrick M. Niedzielski <patrick@pniedzielski.net>
 *
 * Distributed under the Boost Software License, Version 1.0.  (See copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>

int main() {
  using namespace std;

  // Don't skip whitespace
  cin >> noskipws;
  
  auto c = '\0';
  while (cin >> c) cout << c;
}
