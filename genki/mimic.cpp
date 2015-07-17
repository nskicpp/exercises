/* mimic.cpp

   Read from standard in, and print exactly the same thing to standard out.
*/

#include <iostream> // cin, cout

int main() {
    using namespace std;

    cin >> noskipws;
    auto input = '_';
    while (cin >> input) {
        cout << input;
    }
}
