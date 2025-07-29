#include <iostream>
using namespace std;

class Solution
{
public:
    static vector<int> plusOne(vector<int> &digits)
    {
        vector<int>::iterator ite;
        bool stop = false;

        for (ite = digits.end() - 1; ite >= digits.begin() && !stop; ite--)
        {
            *ite += 1;
            if (*ite == 10)
            {
                if (ite - digits.begin() == 0)
                {
                    *ite = 1;
                    digits.push_back(0);
                }
                else
                    *ite = 0;
            }
            else
                return digits;
        }
        return digits;
    }
};