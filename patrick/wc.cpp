/* wc.cpp -- Count the number of words in input
 * Copyright © 2015, Patrick M. Niedzielski <patrick@pniedzielski.net>
 *
 * Distributed under the Boost Software License, Version 1.0.  (See copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <string>

int main() {
  using namespace std;

  auto word = ""s;
  auto count = 0;
  while (cin >> word) ++count;
  
  cout << count << '\n';
}
