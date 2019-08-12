#include "Euclidean/euclidean.h"
#include "Exponentiation/exponentiation.h"
#include "Fibonacci/Fibonacci.h"
#include "PrimeCount/PrimeCount.h"
#include "functional"
#include <chrono>
#include <iostream>

using namespace std;

namespace {
void test(function<void()> func)
{
    if (func) {
        auto start = chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        cout << "Time: " << chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << endl;
    }
}
} // namespace

int main()
{
    cout << "Euclidean" << endl;
    test([]() { cout << "subtraction: " << Euclidean::subtraction(12345678, 12378965) << endl; });
    test([]() { cout << "division: " << Euclidean::division(12345678, 12378965) << endl; });
    cout << endl;

    cout << "Exponentiation" << endl;
    test([]() { cout << "multiplication: " << Exponentiation::multiplication(2, 21) << endl; });
    test([]() {
        cout << "powerMultiplication: " << Exponentiation::powerMultiplication(2, 21) << endl;
    });
    test([]() {
        cout << "powerDecomposition: " << Exponentiation::powerDecomposition(2, 21) << endl;
    });
    cout << endl;

    cout << "PrimeCount" << endl;
    test([]() { cout << "divisions: " << PrimeCount::divisions(10000) << endl; });
    test([]() { cout << "divisionsOptimazed: " << PrimeCount::divisionsOptimazed(10000) << endl; });
    test([]() { cout << "sieve: " << PrimeCount::sieve(10000) << endl; });
    cout << endl;

    cout << "Fibonacci" << endl;
    test([]() { cout << "recursion: " << Fibonacci::recursion(30) << endl; });
    test([]() { cout << "interaction: " << Fibonacci::interaction(30) << endl; });
    test([]() { cout << "GoldenRatio: " << Fibonacci::GoldenRatio(30) << endl; });
    cout << endl;

    return 0;
}
