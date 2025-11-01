#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    static void anti_transpose(vector<vector<int>> &matrix)
    {
        size_t n = matrix.size();
        vector<vector<int>> copy(matrix);
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                matrix[i][j] = copy[n - 1 - j][n - 1 - i];
    }

    static void rotate(vector<vector<int>> &matrix)
    {
        for (vector<int> &row : matrix)
            std::reverse(row.begin(), row.end());
        anti_transpose(matrix);
    }
};