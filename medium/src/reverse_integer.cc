#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int remainder = 0;

        long long res;

        while (x != 0)
        {
            remainder = x % 10;
            x = x / 10;

            res = res * 10 + remainder;
        }

        if (res >= INT32_MAX || res <= INT32_MIN)
            return 0;

        return res;
    }
};