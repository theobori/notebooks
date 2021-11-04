#include "../include/util.hpp"
#include <math.h>

bool Util::Eratosthene(long int n)
{
    long int d = 3;

    if (n < 0)
        return (false);
    if (n % 2 == 0)
        return false;
    while (d <= sqrt(n)) {
        if (n % d == 0)
            return (false);
        d += 2;
    }
    return (true);
}

long int Util::DivSum(int n)
{
    long int ret = 0;

    for (int i = 1; i < (n / 2) + 1; i++)
        ret += (n % i == 0) ? i : 0;
    return (ret);
}

int Util::HowManyDigits(int n)
{
    int digits = 0;

    do {
        n /= 10; 
        digits++;
    } while (n != 0);
    return (digits);
}