/* hello_name.cpp

   Get a user's name, then print them a message.
*/

#include <iostream>
using namespace std;

int main()
{
    string name;

    cout << "Please enter your name:\n"s;
    cin  >> name;
    cout << "Hi "s << name << "!\n"s;

    return EXIT_SUCCESS;
}
