#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int>::iterator ite = nums.begin();
        int k = 0;

        for (int i = 0; ite < nums.end(); i++)
        {
            if (*ite == val)
            {
                nums.erase(ite);
                k += 1;
            }
            else
                ite++;
        }
        return k;
    }
};