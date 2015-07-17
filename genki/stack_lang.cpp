/* stack_lang.cpp

   Interpret the following stack-based language:

   (each token is separated by whitespace)
   NUM     ::= (the format understood by std::stoi)
   OP      ::= + | - | * | /
   PRINT   ::= print
   EXPR    ::= NUM | EXPR PRINT | EXPR EXPR OP
   PROGRAM ::= EXPR
*/

#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // cin, cout
#include <string>
#include <vector>

int main() {
    using namespace std;
    using namespace std::literals; // ""s

    auto stack = vector<int>{};
    auto curr_input = ""s;

    // Loop invariant: Any valid expression from a previous input has been
    // interpreted according to the language rules. If invalid, error out.
    while (cin >> curr_input) {
        if (curr_input == "print"s) {
            if (stack.empty()) {
                cerr << "--> Error: `print` invalid if the stack is empty.\n"s;
                return EXIT_FAILURE;
            } else {
                cout << "--> Stack: "s;
                for (auto num : stack) {
                    cout << num << " "s;
                }
                cout << "\n";
            }
        } else if (curr_input == "+"s || curr_input == "-"s ||
                   curr_input == "*"s || curr_input == "/"s) {
            if (stack.size() < 2) {
                cerr << "--> Error: There must be at least two"s
                     << " values on the stack to use an OP.\n"s;
                return EXIT_FAILURE;
            }

            auto right_half = stack.back();
            stack.pop_back();
            auto left_half = stack.back();
            stack.pop_back();
            if (curr_input == "+"s) {
                stack.push_back(left_half + right_half);
            } else if (curr_input == "-"s) {
                stack.push_back(left_half - right_half);
            } else if (curr_input == "*"s) {
                stack.push_back(left_half * right_half);
            } else if (curr_input == "/"s) {
                if (right_half == 0) {
                    cerr << "--> Error: Divide by zero.\n"s;
                    return EXIT_FAILURE;
                }
                stack.push_back(left_half / right_half);
            }
        } else {
            stack.push_back(stoi(curr_input));
        }

    }

    if (stack.size() != 1) {
        cerr << "--> Error: Valid expressions leave"s
             << " one and only one value on the stack.\n"s;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
