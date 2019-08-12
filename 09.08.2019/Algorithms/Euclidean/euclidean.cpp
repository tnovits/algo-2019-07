
#include "euclidean.h"

uint32_t Euclidean::subtraction(uint32_t first, uint32_t second)
{
    while (first != second) {
        if (first > second) {
            first -= second;
        } else {
            second -= first;
        }
    }

    return first;
}

uint32_t Euclidean::division(uint32_t first, uint32_t second)
{
    while (first != 0 && second != 0) {
        if (first > second) {
            first %= second;
        } else {
            second %= first;
        }
    }

    return first > 0 ? first : second;
}
