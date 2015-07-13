/* hello_name.cpp

   Get a user's first name, then print them a message.
*/

#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // cin, cout
#include <string>

int main() {
    using namespace std::literals;

    std::cout << "Please enter your first name, no spaces:\n"s;

    std::string name;
    std::cin >> name;

    std::cout << "Hi "s << name << "!\n"s;

    return EXIT_SUCCESS;
}
