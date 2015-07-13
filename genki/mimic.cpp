/* mimic.cpp

   Read from standard in, and print exactly the same thing to standard out.
   Line-delimited.
*/

#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // cin, cout
#include <string>

int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Type a message and then press enter.\n"s;

    auto input = ""s;
    while (getline(cin, input)) {
        cout << input << "\n"s;
    }

    cout << "Goodbye!\n"s;

    return EXIT_SUCCESS;
}
