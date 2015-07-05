#include <iostream>
#include <string>

using namespace std;
using namespace std::literals;

int main() {
    cout << "Please enter your first name: "s;
    
    string input;
    getline(cin, input);
    
    if (input.empty()) {
        cout << "\nYou did not provide a name. Exiting.\n"s;
        return 1;
    }
    
    cout << "Hello, "s << input << ".\n"s;
}
