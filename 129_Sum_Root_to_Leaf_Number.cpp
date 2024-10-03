# include <iostream>

using namespace std;

// Definition for a binary tree node.
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
    int sum_helper(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;

        sum = sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr)
            return sum;

        return sum_helper(root->left, sum) + sum_helper(root->right, sum);
    }
public:
    int sumNumbers(TreeNode *root)
    {
        return sum_helper(root,0);
    }
};