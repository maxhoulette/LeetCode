#include <iostream>
using namespace std;

class Solution
{
public:
    static int strStr(string haystack, string needle)
    {
        if (needle.length() > haystack.length())
            return -1;

        int first_occurence = 0;
        bool onGoing = false;

        string::iterator iteHaystack;
        string::iterator iteNeedle = needle.begin();
        for (iteHaystack = haystack.begin(); iteHaystack < haystack.end(); iteHaystack++)
        {
            if (*iteNeedle == *iteHaystack)
            {
                if (!onGoing)
                {
                    first_occurence = iteHaystack - haystack.begin();
                    onGoing = true;
                }

                if (iteNeedle - needle.end() + 1 == 0)
                    return first_occurence;

                iteNeedle++;
            }
            else
            {
                if (onGoing)
                    iteHaystack = haystack.begin() + first_occurence;
                iteNeedle = needle.begin();
                onGoing = false;
                first_occurence = -1;
            }
        }
        return -1;
    }
};