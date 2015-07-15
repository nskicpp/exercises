/*
 * stack_language.cpp - implement a simple stack-based language
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std::literals;

int main() {
    auto stack = std::vector<int>{};

    auto input = ""s;

    // Loop invariant: stack contains evaluated expressions in order of
    // least to most recently evaluated.
    while(std::cin >> input) {
        if (input == "+"s || input == "-"s || input == "*"s || input == "/"s) {
            if (stack.size() < 2) {
                std::cerr << "Stack underflow: "s << input << "\n"s;
                return EXIT_FAILURE;
            }

            auto b = stack.back();
            stack.pop_back();
            auto a = stack.back();
            stack.pop_back();

            if (input == "+"s) {
                stack.push_back(a + b);
            }
            else if (input == "-"s) {
                stack.push_back(a - b);
            }
            else if (input == "*"s) {
                stack.push_back(a * b);
            }
            else if (input == "/"s) {
                stack.push_back(a / b);
            }
            else {
                std::cerr << "Unimplemented operator: "s << input << std::endl;
                return EXIT_FAILURE;
            }
        }
        else if (input == "print"s) {
            std::cout << "Stack contents: "s;
            for (auto val : stack) {
                std::cout << val << " "s;
            }
            std::cout << "\n"s;
        }
        else {
            // We can't use exceptions yet
            for (auto c : input) {
                if (!std::isdigit(c)) {
                    std::cerr << "Invalid token: "s << input << "\n"s;
                    return EXIT_FAILURE;
                }
            }
            stack.push_back(std::stoi(input));
        }
    }

    if (stack.size() > 1) {
        std::cerr << "Have EXPR EXPR, expected OP or PRINT.\n"s;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
