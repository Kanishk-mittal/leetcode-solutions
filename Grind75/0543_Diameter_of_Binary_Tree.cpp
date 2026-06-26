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
    int dfs(TreeNode *root, int &result)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, 1 + left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        dfs(root, result);
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}