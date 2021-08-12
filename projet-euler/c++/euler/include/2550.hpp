#ifndef __2550_HPP__
#define __2550_HPP__

#include <iostream>
#include <cmath>
#include <vector>

#include "../include/util.hpp"

using namespace std;

namespace TwentyFiveToFifty {

#define ABS(x) (((x) < 0) ? -(x) : (x) )

class Problem3: public Integer {

    private:
        long int param = 600851475143;
    public:
        Problem3() {};
        long int solve();
};

class Problem9 {
    private:
        short unsigned int param = 500;
        bool is_pythagorean_triplet(int a, int b, int c);
    public:
        Problem9() {};
        long int solve();
};

class Problem14 {
    private:
    unsigned int param = 1000000;
        int collatz_len(unsigned long long int n);
    public:
        Problem14() {}
        int solve();
};

class Problem23: public Integer{
    private:
        short unsigned int param = 28123;
        bool is_abundant(int n);
        vector<unsigned int> GenerateAbundants(int start, int end);
    public:
        Problem23() {};
        int solve();
};

class Problem27: public Integer{
    private:
        long int f(int n, short int a, short int b);
        int consecutive_primes(short int a, short int b);
    public:
        Problem27() {};
        int solve();
};

class Square {
    private:
        short int h;
        short int w;
        int Area;
    public:
        int **Arr;
        Square(short int width, short int height) {
            w = width;
            h = height;
            Area = w * h;
            Arr = new int*[h];
            for (int i = 0; i < w; i++)
                Arr[i] = new int[w];
        };
        ~Square() {
            for (int i = 0; i < h; i++)
                delete Arr[i];
            delete Arr;
        };
        short int GetW(void) { return w ;};
        short int GetH(void) { return h ;};
        int GetArea(void) { return Area ;};
        void DisplaySquare();
        int SumDiag();
};

class Problem28 {
    private:
        Square square{1001, 1001};
        void InitSquare();
    public:
        Problem28() {};
        int solve();
};

class Problem29 {
    private:
        vector<long double> Arr;
    public:
        Problem29() {};
        bool is_distinct(long double n);
        int solve();
};

class Problem30: public Integer {
    private:
        bool is_good(int n);
    public:
        Problem30() {};
        int solve();
};

}

#endif