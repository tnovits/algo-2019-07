
#include "PrimeCount.h"
#include <cstring>

namespace {
bool *mas = nullptr;
size_t masCount = 0;

bool isPrime(uint32_t number)
{
    uint32_t count = 0;

    for (uint32_t i = 1; i <= number; i++) {
        if (number % i == 0) {
            count++;
        }
    }

    return count == 2;
}

bool isPrimeOptimazed(uint32_t number)
{
    if (number == 2) {
        return true;
    } else if (number % 2 == 0) {
        return false;
    }

    uint32_t i = 3;

    for (; i < masCount; i++) {
        if (mas[i]) {
            if (number % i == 0) {
                return false;
            }
        }
    }

    for (; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

} // namespace

size_t PrimeCount::divisions(uint32_t number)
{
    size_t result = 0;

    for (uint32_t i = 2; i <= number; i++) {
        if (isPrime(i)) {
            result++;
        }
    }

    return result;
}

size_t PrimeCount::divisionsOptimazed(uint32_t number)
{
    size_t result = 0;
    mas = new bool[number + 1];

    for (uint32_t i = 2; i <= number; i++) {
        if ((mas[i] = isPrimeOptimazed(i))) {
            result++;
            masCount++;
        }
    }

    delete[] mas;
    masCount = 0;

    return result;
}

size_t PrimeCount::sieve(uint32_t number)
{
    size_t count = 0;
    mas = new bool[number + 1];
    memset(mas, true, number + 1);

    for (uint32_t i = 2; i <= number; i++) {
        if (mas[i]) {
            for (uint32_t j = i * i; j <= number; j += i) {
                mas[j] = false;
            }
        }
    }

    for (uint32_t i = 2; i <= number; i++) {
        if (mas[i]) {
            count++;
        }
    }

    delete[] mas;
    masCount = 0;

    return count;
}
