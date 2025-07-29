#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int sqrt = 0;

        while (pow(sqrt, 2) > x || pow(sqrt + 1, 2) <= x)
        {
            if (pow(sqrt, 2) > x)
                sqrt = (sqrt + 0) / 2;
            else
                sqrt = (sqrt + x) / 2;
        }
        return sqrt;
    }
};