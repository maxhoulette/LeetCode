#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        auto it = remove(nums.begin(), nums.end(), 0);
        nums.erase(it, nums.end());
        
        int number_of_zeros = n - nums.size();
        for (int i = 0; i < number_of_zeros; i++)
            nums.push_back(0);
    }
};