#include <iostream>

// Precondition: input number is a valid, positive trinary number. It can 
// have a decimal point, but not exponents.
int main() {
    using namespace std;
    using namespace std::literals;

    cout << "Please enter a number in trinary: "s;
    
    auto s = ""s;
    getline(cin, s);
    
    auto n = 0.0;
    auto place_value_denominator = 1.0;
    auto seen_decimal_point = false;

    // Loop invariant:
    // n is equal to the decimal equivalent of the trinary characters
    // seen so far. place_value_denominator is equal to 
    // 3^(number of digits seen to right of decimal point)
    for (char c : s) {
        if (c == '.' && !seen_decimal_point) {
            seen_decimal_point = true;
            continue;
        }

        if (seen_decimal_point) {
            place_value_denominator *= 3.0;
                 if (c == '0') /* no change */ ;
            else if (c == '1') n += 1.0 / place_value_denominator;
            else if (c == '2') n += 2.0 / place_value_denominator;
        }
        
        else {
                 if (c == '0') n = n * 3;
            else if (c == '1') n = n * 3 + 1.0;
            else if (c == '2') n = n * 3 + 2.0;
        }
    }
    
    cout << "Decimal equivalent: "s << n << "\n"s;
}
