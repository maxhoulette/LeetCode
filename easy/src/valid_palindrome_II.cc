#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    bool isLimits(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return isLimits(s, left + 1, right) || isLimits(s, left, right - 1);
            left++;
            right--;
        }
        return true;
    }
};