#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    // Set x to 1/x and n to -n in case n is negative
    static void switch_x_n(double &x, int &n)
    {
        if (n != INT32_MIN)
        {
            x = 1 / x;
            n = -n;
        }
        else
        {
            n = INT32_MAX;
            x = (1 / x) * (1 / x);
        }
    }

    static double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            switch_x_n(x, n);

        cout << n << endl;

        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
};