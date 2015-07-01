/**
 * prompt_name.cpp - a program that prompts the user for their name and
 * echoes it back to them
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std::literals;

int main() {
    std::string user_name;
    std::cout << "Please enter your name: "s;
    std::getline(std::cin, user_name);
    std::cout << "Hello, "s << user_name << "!\n"s;
    return EXIT_SUCCESS;
}
