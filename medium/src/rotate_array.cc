#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    static void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n > 1)
        {

            k = k <= n ? k : k % n;

            vector<int>::iterator ite = nums.end() - k;
            vector<int> res;

            for (int index = 0; index < n; index++)
            {
                if (ite == nums.end())
                    ite = nums.begin();

                res.push_back(*ite);
                ite++;
            }
            nums = res;
        }
    }

    static void rotateOptimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n > 1)
        {
            k = k <= n ? k : k % n;
            std::reverse(nums.begin(), nums.end());
            std::reverse(nums.begin(), nums.begin() + k);
            std::reverse(nums.begin() + k, nums.end());
        }
    }
};