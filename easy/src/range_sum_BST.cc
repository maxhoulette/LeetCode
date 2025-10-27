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
    static int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;

        bool is_inside = root->val >= low && root->val <= high;

        return is_inside ? root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high)
                         : rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};