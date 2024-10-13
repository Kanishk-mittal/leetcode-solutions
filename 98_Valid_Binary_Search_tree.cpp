# include <iostream>
# include <vector>
# include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private: 
    bool check_bst(TreeNode *root, long long min, long long max)
    {
        if (!root)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return check_bst(root->left, min, root->val) && check_bst(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode *root)
    {
        return check_bst(root, LLONG_MIN, LLONG_MAX);
    }
};
