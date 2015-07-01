/*
 * prompt_name.cpp - a program that prompts the user for their name and
 * uses it to greet them
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace std::literals;

int main() {
    string user_name;
    cout << "Please enter your name: "s;
    cin >> user_name;
    cout << "Hello, " << user_name << "!\n"s;
    return EXIT_SUCCESS;
}
