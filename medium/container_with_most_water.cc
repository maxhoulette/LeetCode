#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_volume = -1;
        int current_volume = 0;

        vector<int>::iterator iteLeft = height.begin();
        vector<int>::iterator iteRight = height.end() - 1;

        while (iteLeft < iteRight)
        {
            current_volume = min(*iteLeft, *iteRight) * (iteRight - iteLeft);
            if (current_volume > max_volume)
                max_volume = current_volume;
            
            if (*iteLeft > *iteRight)
                iteRight--;
            else 
                iteLeft++;
        }

        return max_volume;
    }
};