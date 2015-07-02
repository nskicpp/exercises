#include <iostream>
#include <string>

using namespace std;
using namespace std::literals;

int main() {
    cout << "Please enter your first name: "s;
    
    string input;
    cin >> input;
    
    cout << "Hello, "s << input << ".\n"s;
}
