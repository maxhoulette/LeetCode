#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string res = "";
        string current = "";
        size_t pos;

        for (char c : s)
        {
            pos = current.find(c);
            if (pos != string::npos)
                current.erase(0, pos + 1);

            current += c;

            if (current.length() > res.length())
                res = current;
        }

        return res.length();
    }
};
