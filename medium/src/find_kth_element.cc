#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    static int findKthLargest(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
};