#include "../include/2550.hpp"

using namespace std;
using namespace TwentyFiveToFifty;

long int Problem3::solve()
{
    long int _max = 0;

    for (long int i = 3; i < sqrt(param); i++) {
        if (param % i==0 && Eratosthene(i) && i > _max)
            _max = i;
    }
    return (_max);
}

bool Problem9::is_pythagorean_triplet(int a, int b, int c)
{
    if (!(a < b && b < c))
        return false;
    return (pow(a, 2) + pow(b, 2) == pow(c, 2));
}

long int Problem9::solve()
{
    for (int a = 0; a < param; a++) {
        for (int b = 0; b < param; b++) {
            for (int c = 0; c < param; c++) {
                if (is_pythagorean_triplet(a, b, c) && (a + b + c == 1000))
                    return (a * b * c);
            }
        }
    }
    return (0);
}

int Problem14::collatz_len(unsigned long long int n)
{
    int round = 0;

    while (n != 1) {
        n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
        round++;
    }
    return (round);
}

int Problem14::solve()
{
    int _max_len = 0;
    int _max = 0;
    int tmp = 0;

    for (unsigned long long int i = 1; i < param; i++) {
        tmp = collatz_len(i);
        if (tmp > _max_len) {
            _max_len = tmp;
            _max = i;
        }
    }
    return (_max);
}

bool Problem23::is_abundant(int n)
{
    return (DivSum(n) > n);
}

vector<unsigned int> Problem23::GenerateAbundants(int start, int end)
{
    vector<unsigned int> ret;

    for (unsigned int i = start; i < end; i++)
        if (is_abundant(i))
            ret.push_back(i);
    return (ret);
}

int Problem23::solve()
{
    vector<unsigned int> abundants = GenerateAbundants(1, param);
    unsigned int sums[param + 1] = { 0 };
    int _sum = 0;
    int ret = 0;

    for (int x = 0; x < abundants.size(); x++) {
        for (int y = x; y < abundants.size(); y++) {
            _sum = abundants[x] + abundants[y];
            if (_sum <= param && sums[_sum] == 0)
                sums[_sum] = _sum;
        }
    }
    for (int i = 0; i < (param); i++)
        ret += (sums[i] == 0) ? i : 0;
    return (ret);
}

long int Problem27::f(int n, short int a, short int b)
{
    return ((n * n) + (a * n) + b);
}

int Problem27::consecutive_primes(short int a, short int b)
{
    int n = 0;

    for (; Eratosthene(f(n, a, b)); n++);
    return (n);
}

int Problem27::solve()
{
    int _max = 0;
    int consecutive = 0;
    int ret = 0;

    for (short int a = -999; a < 1000; a++) {
        for (short int b = a ; b <= 1000; b++) {
            consecutive = consecutive_primes(a, b);
            if (consecutive > _max) {
                _max = consecutive;
                ret = a * b;
            }
        }
    }
    return (ret);
}

void Square::DisplaySquare()
{
    for (int h = 0; h < GetH(); h++) {
        for (int w = 0; w < GetW(); w++)
            cout << Arr[h][w] << " ";
        cout << endl;
    }
}

int Square::SumDiag()
{
    int ret = 0;
    int x = 0;
    int y = 0;

    for (; x < w && y < h; x++, y++)
        ret += Arr[y][x];
    y--;
    for (x = 0; x < w && y >= 0; x++, y--)
        ret += Arr[y][x];
    return (ret - 1);
}

void Problem28::InitSquare()
{
    int i = 1;
    int tmp = 0;
    int round = 1;
    int x = square.GetW() / 2;
    int y = square.GetH() / 2;

    while (i < square.GetArea() - square.GetW() - 1) {
        for (tmp = x; x < tmp + 2 * round - 1; x++, i++) square.Arr[y][x] = i;
        for (tmp = y; y < tmp + 2 * round - 1; y++, i++) square.Arr[y][x] = i;
        for (tmp = x; x > tmp - 2 * round; x--, i++) square.Arr[y][x] = i;
        for (tmp = y; y > tmp - 2 * round; y--, i++) square.Arr[y][x] = i;
        round++;
    }
    for (tmp = x; x < tmp + 2 * round - 1; x++, i++) square.Arr[y][x] = i;
}

int Problem28::solve()
{
    InitSquare();
    return (square.SumDiag());
}

bool Problem29::is_distinct(long double n)
{
    for (int i = 0; i < Arr.size(); i++)
        if (Arr[i] == n)
            return (false);
    return (true);
}

int Problem29::solve()
{
    long double tmp = 0;

    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            tmp = pow(a, b);
            if (is_distinct(tmp))
                Arr.push_back(tmp);
        }
    }
    return (Arr.size());
}

bool Problem30::is_good(int n)
{
    int _sum = 0;
    int tmp = n;

    for (; n != 0; n /= 10)
        _sum += pow(n % 10, 5);
    return (_sum == tmp);
}

int Problem30::solve()
{
    int ret = 0;

    for (int i = 2; i < 295246; i++)
        ret += (is_good(i)) ? i : 0;
    return (ret);
}

bool Problem34::is_good(int n)
{
    long int tmp = n;
    long int _sum = 0;

    for (; n != 0; n /= 10)
        _sum += Factorial <long int> (n % 10);
    return (_sum == tmp);
}

int Problem34::solve()
{
    int _sum = 0;

    for (int i = 3; i <= 1499999; i++) {
        _sum += (is_good(i)) ? i : 0;
    }
    return (_sum);
}