#ifndef __UTIL_HPP__
#define __UTIL_HPP__

class Util {
    public:
        bool Eratosthene(long int n);
        long int DivSum(int n);
        int HowManyDigits(int n);

        template <typename T>
        T Factorial(T n);
};

template <typename T>
T Util::Factorial(T n)
{
    T ret = 1;

    for (T i = 1; i <= n; i++)
        ret *= i;
    return (ret);
}

#endif