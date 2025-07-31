#include <iostream>
using namespace std;

class Solution
{
public:
    static string addBinary(string a, string b)
    {
        string::iterator iteA = a.end() - 1;
        string::iterator iteB = b.end() - 1;

        string res = "";
        int val = 0;
        int old_val = 0;
        int remainder = 0;
        for (int k = 0; iteA >= a.begin() || iteB >= b.begin(); iteA--, iteB--)
        {
            val = 0;
            if (iteA >= a.begin())
                val += *iteA - '0';
            if (iteB >= b.begin())
                val += *iteB - '0';

            old_val = val;

            val = (val + remainder) % 2;
            remainder = old_val + remainder > 1 ? 1 : 0;
            res = to_string(val) + res;
        }

        if (remainder == 1)
            res = to_string(remainder) + res;

        return res;
    }
};