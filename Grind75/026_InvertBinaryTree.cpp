#include <iostream>
#include <bits/stdc++.h>
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
private:
    void invert(TreeNode *node)
    {
        if (!node)
            return;

        // Swap left and right children
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively invert left and right subtrees
        invert(node->left);
        invert(node->right);
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};

int main()
{
    Solution sol;
    return 0;
}