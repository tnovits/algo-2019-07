
#include "exponentiation.h"

uint64_t Exponentiation::multiplication(uint32_t base, uint32_t power)
{
    uint64_t result = 1;

    for (uint32_t i = 0; i < power; i++) {
        result *= base;
    }

    return result;
}

uint64_t Exponentiation::powerMultiplication(uint32_t base, uint32_t power)
{
    uint64_t result = 1;

    if (power > 0) {
        result = base;
        uint32_t i = 1;

        for (; i << 1 < power; i <<= 1) {
            result *= result;
        }

        for (; i < power; i++) {
            result *= base;
        }
    }

    return result;
}

uint64_t Exponentiation::powerDecomposition(uint32_t base, uint32_t power)
{
    uint64_t result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result *= base;
        }

        base *= base;
        power /= 2;
    }

    return power > 0 ? result * base : result;
}
