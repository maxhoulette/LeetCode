#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int>::iterator ite_1;
        vector<int>::iterator ite_2;

        int first_int;
        int second_int;
        int first_index;
        int second_index;
        vector<int> solution;

        bool stop = false;
        for (ite_1 = nums.begin(); ite_1 < nums.end() && !stop; ite_1++)
            for (ite_2 = ite_1; ite_2 < nums.end() && !stop; ite_2++)
            {
                if (distance(ite_1, ite_2) != 0 && *ite_1 + *ite_2 == target)
                {
                    first_int = *ite_1;
                    second_int = *ite_2;
                    first_index = ite_1 - nums.begin();
                    second_index = ite_2 - nums.begin();
                    stop = true;
                }
            }

        solution.push_back(first_index);
        solution.push_back(second_index);

        return solution;
    }
};