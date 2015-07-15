/*
 * prime_factors.cpp - print the prime factors of a number
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std::literals;

int main() {
    auto input = ""s;
    std::cin >> input;

    auto number = std::stoi(input);

    if (number < 2) {
        std::cout << number << " has no prime factors.\n"s;
        return EXIT_SUCCESS;
    }

    // Start it off with just one prime.
    auto primes = std::vector<int>{2};
    auto divisors = std::vector<int>{};
    auto remainder = number;

    // Loop invariant: prime is a known prime, remainder is a divisor of our
    // input number, and divisors contains a known prime p if and only if p
    // divides our input number.
    for (auto prime : primes) {
        if (remainder % prime == 0) {
            divisors.push_back(prime);
        }
        while (remainder % prime == 0) {
            remainder /= prime;
        }
    }

    // Loop invariant: i is an odd number, remainder is a divisor of our
    // input number, and divisors contains i if and only if i is prime and i
    // divides our input number. Stop iterating when i^2 > remainder, since
    // any composite number must have a divisor less than or equal to its
    // square root.
    for (auto i = primes.back() + 1; i*i <= remainder; i += 2) {
        auto is_prime = true;
        // Loop invariant: prime is a known prime, and is_prime will be
        // false if and only if some prime p divides i.
        for (auto prime : primes) {
            if (i % prime == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            if (remainder % i == 0) {
                divisors.push_back(i);
            }
            while (remainder % i == 0) {
                remainder /= i;
            }
            primes.push_back(i);
        }
    }

    // remainder is a divisor of our input number by our invariant
    // above. And since we stopped iterating, that means we did not find a
    // divisor of remainder less than or equal to its square root, so it
    // must be prime itself.
    if (remainder > 1) {
        divisors.push_back(remainder);
    }

    std::cout << "Prime factors of "s << number << ":"s;

    for (auto prime : divisors) {
        std::cout << " "s << prime;
    }

    return EXIT_SUCCESS;
}
