#include <iostream>

int main() {
    using namespace std;
    using namespace std::literals;

    auto s = ""s;
    auto count = 0;
    while (cin >> s)
        ++count;

    cout << count << "\n"s;
}
