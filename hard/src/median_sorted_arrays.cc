#include <iostream>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<int>::iterator ite1 = nums1.begin();
        vector<int>::iterator ite2 = nums2.begin();

        vector<int> concat;

        for (int i = 0; ite1 < nums1.end() || ite2 < nums2.end(); i++)
        {
            if (ite1 < nums1.end())
            {
                if (ite2 < nums2.end())
                {
                    if (*ite1 < *ite2)
                    {
                        concat.push_back(*ite1);
                        ite1++;
                    }
                    else
                    {
                        concat.push_back(*ite2);
                        ite2++;
                    }
                }
                else
                {
                    concat.push_back(*ite1);
                    ite1++;
                }
            }
            else
            {
                concat.push_back(*ite2);
                ite2++;
            }
        }

        if ((m + n) % 2 == 0)
        {
            return (concat[(m + n) / 2 - 1] + concat[(m + n) / 2]) * 0.5;
        }
        else
        {
            return concat[(m + n - 1) / 2];
        }
    }
};