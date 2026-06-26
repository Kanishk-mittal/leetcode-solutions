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
    void dfs(TreeNode *root, vector<int> &inorder)
    {
        if (root->left)
        {
            dfs(root->left, inorder);
        }
        inorder.push_back(root->val);
        if (root->right)
        {
            dfs(root->right, inorder);
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        dfs(root, inorder);
        return inorder[k - 1];
    }
};
/*
inorder traversal gives us the sorted order we can use that
*/

int main()
{
    Solution sol;
    return 0;
}