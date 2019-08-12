
#include "Fibonacci.h"
#include <cmath>

uint64_t Fibonacci::recursion(uint16_t number)
{
    if (number < 3) {
        return 1;
    } else {
        return recursion(number - 1) + recursion(number - 2);
    }
}

uint64_t Fibonacci::interaction(uint16_t number)
{
    uint32_t number1 = 1;
    uint32_t number2 = 1;
    uint32_t result = 1;

    for (uint32_t i = 3; i <= number; i++) {
        result = number1 + number2;
        number1 = number2;
        number2 = result;
    }

    return result;
}

uint64_t Fibonacci::GoldenRatio(uint16_t number)
{
    static double Q = (1 + std::sqrt(5)) / 2;
    uint64_t result = 1;

    if (number > 2) {
        result = static_cast<uint64_t>(std::pow(Q, number) / std::sqrt(5)
                                       + static_cast<double>(1) / 2);
    }

    return result;
}
