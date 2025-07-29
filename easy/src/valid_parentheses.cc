#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        string::iterator ite;
        vector<char> lastOpen;

        for (ite = s.begin(); ite <= s.end(); ite++)
        {
            if (*ite == '(')
                lastOpen.push_back(*ite);
            else if (*ite == '{')
                lastOpen.push_back(*ite);
            else if (*ite == '[')
                lastOpen.push_back(*ite);

            if (*ite == ')' || *ite == '}' || *ite == ']')
            {
                if (lastOpen.size() == 0)
                    return false;
                else
                {
                    if (*ite == ')' && lastOpen.back() != '(')
                        return false;
                    else if (*ite == '}' && lastOpen.back() != '{')
                        return false;
                    else if (*ite == ']' && lastOpen.back() != '[')
                        return false;
                }
                lastOpen.pop_back();
            }
        }

        return lastOpen.size() == 0;
    }
};