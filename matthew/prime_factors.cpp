#include <iostream>
#include <vector>
#include <cmath>

// Precondition: Input to program is a positive number understood by std::stoi
int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Enter a positive integer: "s;
    auto s = ""s;
    cin >> s;

    auto n = stoi(s);

    if (n < 2) {
        cout << "Prime factors: [none]\n"s;
        return 0;
    }

    auto primes = vector<int>{};
    auto i = 2;

    // Loop invariant: 
    // No integer in [2, i) divides n. 
    // (Consequently, if i divides n, then i is prime.)
    while (i*i <= n) { // i <= sqrt(n)
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0)
                n /= i;
        }

        if (i == 2) i = 3;
        else        i += 2;
    }
    
    if (n > 1)
        primes.push_back(n);

    cout << "Prime factors:"s;
    for (auto p : primes)
        cout << " "s << p;
    cout << "\n"s;
}
