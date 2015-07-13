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
#include <tuple>
#include <vector>

int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Type a well-formed expression on one line.\n"s
         << "To evaluate, press [ENTER]. To then exit, press [CTRL-D].\n"s;

    auto stack = vector<long>{};
    auto curr_input = ""s;

    // Loop invariant: Any input from a previous iteration has been interpreted
    // according to the language rules.
    while (cin >> curr_input) {
        if (curr_input == "print"s) {
            if (stack.empty()) {
                cout << "--> The stack is currently empty."s;
            } else {
                cout << "--> The stack is currently: "s;
                for (auto num : stack) {
                    cout << num << " "s;
                }
            }
            cout << "\n";
        } else if (curr_input == "+"s || curr_input == "-" ||
                   curr_input == "*"s || curr_input == "/") {
            if (stack.size() < 2) {
                cerr << "--> Ignored invalid input: There must be at least two"s
                     << " values on the stack to use an OP.\n"s;
                continue;
            }

            auto second_num = stack.back();

            if (second_num == 0 && curr_input == "/"s) {
                cerr << "--> Ignored invalid input: Divide by zero.\n"s;
                continue;
            }

            stack.pop_back();
            auto first_num = stack.back();
            stack.pop_back();
            if (curr_input == "+"s) {
                stack.push_back(first_num + second_num);
            } else if (curr_input == "-"s) {
                stack.push_back(first_num - second_num);
            } else if (curr_input == "*"s) {
                stack.push_back(first_num * second_num);
            } else if (curr_input == "/"s) {
                stack.push_back(first_num / second_num);
            }
        } else {
            try {
                stack.push_back(stoi(curr_input));
            } catch (out_of_range) {
                cerr << "--> Ignored out-of-range input: <"s
                    << curr_input << ">.\n"s;
            } catch (invalid_argument) {
                cerr << "--> Ignored invalid input: <"s
                     << curr_input << ">.\n"s;
            }
        }
    }

    cout << "--> Goodbye!\n"s;
    return EXIT_SUCCESS;
}
