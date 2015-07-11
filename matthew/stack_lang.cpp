#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace std::literals;

// Precondition: Anything besides "+", "-", "*", "/", and "print" in the input
// must be a number understood by std::stoi
int main() {
    auto only_numbers = true;
    auto stack = vector<int>{};

    auto s = ""s;
    while (cin >> s) {

        // op
        if (s == "+"s || s == "-"s || s == "*"s || s == "/"s) {
            if (stack.size() < 2) {
                cerr << "Input malformed; insufficient operands.\n"s;
                exit(EXIT_FAILURE);
            }
            auto right = stack.back(); stack.pop_back();
            auto left  = stack.back(); stack.pop_back();
            
            int result;
                 if (s == "+"s) result = left + right;
            else if (s == "-"s) result = left - right;
            else if (s == "*"s) result = left * right;
            else {// s == "/"s
                if (right == 0) {
                    cerr << "Input malformed; division by zero.\n"s;
                    exit(EXIT_FAILURE);
                }
                result = left / right;
            }

            stack.push_back(result);
            only_numbers = false;
        }

        // print
        else if (s == "print"s) {
            cout << "Stack contents:"s;
            for (auto n : stack)
                cout << " "s << n;
            cout << "\n"s;
            only_numbers = false;
        }

        // num
        else stack.push_back(stoi(s));
    }

    if (only_numbers) {
        cout << "Input malformed; program is not an expression.\n"s;
        return EXIT_FAILURE;
    }
}
