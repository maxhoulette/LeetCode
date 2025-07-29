#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT32_MIN)
        {
            if (divisor == -1)
            {
                return INT32_MAX;
            }
            else if (divisor == 1)
                return INT32_MIN;
        }

        int sign = -1;
        if ((dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0))
            sign = 1;

        int result = 0;

        bool condition = dividend == INT32_MIN ? true : abs(dividend) >= abs(divisor);

        while (condition)
        {
            dividend -= sign * divisor;
            result += 1;

            condition = abs(dividend) >= abs(divisor);
        }
        return sign * result;
    }
};