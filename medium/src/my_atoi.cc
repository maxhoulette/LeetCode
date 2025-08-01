#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    static int myAtoi(string s)
    {
        long long res = 0;
        vector<int> res_vec;
        int sign = 0;
        size_t pos;
        bool stop = false;
        bool one_not_zero = false;
        string numbers_char = "0123456789";

        string::iterator iteS;
        for (iteS = s.begin(); iteS < s.end() && !stop; iteS++)
        {
            if (*iteS == ' ')
            {
                if (!res_vec.empty() || sign != 0)
                    stop = true;
            }
            else if (*iteS == '0')
            {
                if (res_vec.empty() || one_not_zero)
                    res_vec.push_back(0);
            }
            else if (*iteS == '-' || *iteS == '+')
            {
                if (res_vec.empty() && sign == 0)
                    sign = *iteS == '-' ? -1 : 1;
                else
                    stop = true;
            }
            else
            {
                pos = numbers_char.find(*iteS);
                if (pos != string::npos)
                {
                    one_not_zero = true;
                    res_vec.push_back(pos);
                    if (sign == 0)
                        sign = 1;
                }
                else
                    stop = true;
            }
        }

        for (size_t i = 0; i < res_vec.size(); i++)
        {
            res += res_vec[res_vec.size() - i - 1] * pow(10, i);

            if (sign * res <= INT32_MIN || sign * pow(10, i) <= INT32_MIN)
                return INT32_MIN;
            else if (sign * res >= INT32_MAX || sign * pow(10, i) >= INT32_MAX)
                return INT32_MAX;
        }

        return sign * res;
    }
};
