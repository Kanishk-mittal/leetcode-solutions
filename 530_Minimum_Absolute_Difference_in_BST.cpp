# include <iostream>

using namespace std;

//Definition for a binary tree node.
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
    void inorder(TreeNode *root, TreeNode *&prev, int &minDiff)
    {
        if (!root)
            return;
        inorder(root->left, prev, minDiff);
        if (prev)
            minDiff = min(minDiff, root->val - prev->val);
        prev = root;
        inorder(root->right, prev, minDiff);
    }
public:
    int getMinimumDifference(TreeNode *root)
    {
        int minDiff = INT_MAX;
        TreeNode *prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};