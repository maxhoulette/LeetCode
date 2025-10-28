#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int *previous;
    int res;

    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            if (previous)
                res = min(res, abs(root->val - *previous));
            previous = &root->val;
            dfs(root->right);
        }
    }

    int getMinimumDifference(TreeNode *root)
    {
        previous = nullptr;
        res = INT32_MAX;

        dfs(root);
        return res;
    }
};