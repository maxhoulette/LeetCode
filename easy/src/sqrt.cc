#include <iostream>
using namespace std;

class Solution
{
public:
    static int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;

        double sqrt = x / 2;
        double x_max = x;
        double x_min = 0;

        while (pow(int(sqrt), 2) > x || pow(int(sqrt) + 1, 2) <= x)
        {
            if (pow(int(sqrt), 2) > x)
            {
                x_max = sqrt;
                sqrt = (sqrt + x_min) * 0.5;
            }
            else
            {
                x_min = sqrt;
                sqrt = (sqrt + x_max) * 0.5;
            }
        }
        return int(sqrt);
    }
};