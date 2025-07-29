#include <iostream>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;

        string::iterator ite;
        for (ite = s.begin(); ite < s.end(); ite++)
        {
            if (*ite == 'M')
                res += 1000;
            else if (*ite == 'D')
                res += 500;
            else if (*ite == 'L')
                res += 50;
            else if (*ite == 'V')
                res += 5;
            else if (*ite == 'C')
            {
                if (ite - s.end() + 1 == 0)
                    res += 100;
                else
                {
                    if (*(ite + 1) == 'D' || *(ite + 1) == 'M')
                        res -= 100;
                    else
                        res += 100;
                }
            }
            else if (*ite == 'X')
            {
                if (ite - s.end() + 1 == 0)
                    res += 10;
                else
                {
                    if (*(ite + 1) == 'L' || *(ite + 1) == 'C')
                        res -= 10;
                    else
                        res += 10;
                }
            }
            else if (*ite == 'I')
            {
                if (ite - s.end() + 1 == 0)
                    res += 1;
                else
                {
                    if (*(ite + 1) == 'V' || *(ite + 1) == 'X')
                        res -= 1;
                    else
                        res += 1;
                }
            }
        }
        return res;
    }
};