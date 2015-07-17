/* word_count.cpp

   Read from standard in, and print the number of words read.
   Words are determined by whitespace-delimination.
*/

#include <iostream> // cin, cout
#include <string>

int main() {
    using namespace std;
    using namespace std::literals; // ""s

    auto count = 0;
    auto input = ""s;
    while (cin >> input) {
        ++count;
    }

    cout << count << "\n"s;
}
