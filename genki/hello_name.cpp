/* hello_name.cpp

   Get a user's first name, then print them a message.
*/

#include <string>
#include <cstdlib>
#include <iostream>

int main() {
    using namespace std::literals;

    std::cout << "Please enter your first name, no spaces:\n"s;

    std::string name;
    std::cin >> name;

    std::cout << "Hi "s << name << "!\n"s;

    return EXIT_SUCCESS;
}
