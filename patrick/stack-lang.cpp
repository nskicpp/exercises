/* stack-lang.cpp -- Implements a stack-based calculator
 * Copyright © 2015, Patrick M. Niedzielski <patrick@pniedzielski.net>
 *
 * Distributed under the Boost Software License, Version 1.0.  (See copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

int main() {
  using namespace std;

  auto results_stack = vector<int>{};

  // Loop invariant: All expressions encountered so far in the token stream have
  // been evaluated down to a single value each.
  auto token = ""s;
  while (cin >> token) {
    
    if (token == "print"s) {
      for (auto result : results_stack)
        cout << result << ' ';
      cout << '\n';
    }
    // The following blocks seem very similar except for two characters
    // each…this seems like a good place to build an abstraction, right?  We'll
    // learn how next lesson.
    else if (token == "+"s) {
      if (static_cast<int>(results_stack.size()) < 2) {
        cerr << "Not enough arguments supplied to operator\n"s;
        return EXIT_FAILURE;
      }
      
      auto rhs = results_stack.back();
      results_stack.pop_back();
      auto lhs = results_stack.back();
      results_stack.pop_back();

      results_stack.push_back(lhs + rhs);
    } else if (token == "-"s) {
      if (static_cast<int>(results_stack.size()) < 2) {
        cerr << "Not enough arguments supplied to operator\n"s;
        return EXIT_FAILURE;
      }
      
      auto rhs = results_stack.back();
      results_stack.pop_back();
      auto lhs = results_stack.back();
      results_stack.pop_back();

      results_stack.push_back(lhs - rhs);
    } else if (token == "*"s) {
      if (static_cast<int>(results_stack.size()) < 2) {
        cerr << "Not enough arguments supplied to operator\n"s;
        return EXIT_FAILURE;
      }
      
      auto rhs = results_stack.back();
      results_stack.pop_back();
      auto lhs = results_stack.back();
      results_stack.pop_back();

      results_stack.push_back(lhs * rhs);
    } else if (token == "/"s) {
      if (static_cast<int>(results_stack.size()) < 2) {
        cerr << "Not enough arguments supplied to operator\n"s;
        return EXIT_FAILURE;
      }
      auto rhs = results_stack.back();
      results_stack.pop_back();
      auto lhs = results_stack.back();
      results_stack.pop_back();

      results_stack.push_back(lhs / rhs);
    } else {
      auto val = stoi(token);
      results_stack.push_back(val);
    }
    
  }

  // At the end, if we have more than one value in the stack, the expression was
  // ill-formed.
  if (static_cast<int>(results_stack.size()) > 1) {
      cerr << "Invalid program: only one expression is allowed per program\n"s;
      return EXIT_FAILURE;
    }
}
