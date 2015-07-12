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

    std::string input;

    std::cin >> input;
    while(std::cin) {
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
                std::cerr << "Internal error.\n"s;
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
                switch (c) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    break;
                default:
                    std::cerr << "Invalid token: "s << input << "\n"s;
                    return EXIT_FAILURE;
                }
            }
            stack.push_back(std::stoi(input));
        }
        std::cin >> input;
    }

    return EXIT_SUCCESS;
}
