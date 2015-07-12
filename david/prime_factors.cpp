/*
 * prime_factors.cpp - print the prime factors of a number
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std::literals;

int main() {
    std::string input;
    std::cin >> input;

    auto number = long{ std::stol(input) };

    if (number < 2) {
        std::cout << number << " has no prime factors.\n"s;
        return EXIT_SUCCESS;
    }

    auto primes = std::vector<int>{2, 3, 5, 7};
    auto divisors = std::vector<int>{};
    auto remainder = number;

    for (auto prime : primes) {
        if (remainder % prime == 0) {
            divisors.push_back(prime);
        }
        while (remainder % prime == 0) {
            remainder /= prime;
        }
    }

    // Try only odd numbers.
    for (auto i = primes.back() + 2; i*i <= remainder; i+=2) {
        auto isPrime = true;
        for (auto prime : primes) {
            if (i % prime == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            if (remainder % i == 0) {
                divisors.push_back(i);
            }
            while (remainder % i == 0) {
                remainder /= i;
            }
            primes.push_back(i);
        }
    }

    if (remainder > 1) {
        divisors.push_back(remainder);
    }

    std::cout << "Prime factors of "s << number << ":"s;

    for (auto prime : divisors) {
        std::cout << " "s << prime;
    }

    return EXIT_SUCCESS;
}
