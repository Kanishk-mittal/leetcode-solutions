#include <iostream>
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
private:
    bool check_equal(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return check_equal(left->left, right->right) && check_equal(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        return check_equal(left, right);
    }
};