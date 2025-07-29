#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else
        {
            vector<int> decomposition;

            int remainder = x % 10;
            x = (x - remainder) / 10;

            decomposition.push_back(remainder);

            while (x > 0)
            {
                remainder = x % 10;
                x = (x - remainder) / 10;

                decomposition.push_back(remainder);
            }
            vector<int> decomposition_reverse = decomposition;

            reverse(decomposition_reverse.begin(), decomposition_reverse.end());

            return decomposition_reverse == decomposition;
        }
    }
};