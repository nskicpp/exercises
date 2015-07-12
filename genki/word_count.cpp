/* word_count.cpp

   Read from standard in, and print the number of words read.
   Words are determined by space-delimination.
*/

#include <cstdlib>  // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream> // cin, cout, fixed
#include <string>

int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Type a message. When finished, press [ENTER], then [CTRL-D].\n"s;

    string input;
    auto count = 0;
    while (cin >> input) {
        ++count;
    }

    cout << "\nWord Count: "s << count << "\n"s;

    return EXIT_SUCCESS;
}
