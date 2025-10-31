#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    static bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = 0;
        while (matrix.size() != 1)
        {
            n = int(matrix.size() / 2);
            if (target <= matrix[n - 1].back())
                matrix = vector<vector<int>>(matrix.begin(), matrix.begin() + n);
            else
                matrix = vector<vector<int>>(matrix.begin() + n, matrix.end());
        }
        return find(matrix.front().begin(), matrix.front().end(), target) != matrix.front().end();
    }

    static bool searchMatrix_rec(const vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 1)
            return find(matrix.front().begin(), matrix.front().end(), target) != matrix.front().end();

        if (target <= matrix[int(matrix.size() / 2) - 1].back())
            return searchMatrix_rec(vector<vector<int>>(matrix.begin(), matrix.begin() + int(matrix.size() / 2)), target);
        else
            return searchMatrix_rec(vector<vector<int>>(matrix.begin() + int(matrix.size() / 2), matrix.end()), target);
    }
};