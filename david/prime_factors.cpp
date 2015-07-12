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

    auto number = std::stoi(input);
    auto primes = std::vector<int>{2, 3, 5, 7};

    for (auto i = primes.back() + 1; i <= number; i++) {
        auto isPrime = true;
        for (auto prime : primes) {
            if (i % prime == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }

    if (number < 2) {
        std::cout << number << " has no prime factors.\n"s;
        return EXIT_SUCCESS;
    }

    std::cout << "Prime factors of "s << number << ":"s;

    for (auto prime : primes) {
        if (number % prime == 0) {
            std::cout << " "s << prime;
        }
    }

    return EXIT_SUCCESS;
}
