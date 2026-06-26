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
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&result)
    {
        if (root == nullptr)
            return false;

        if (result != nullptr)
        {
            return true;
        }

        bool self = (root == p || root == q);

        bool left = dfs(root->left, p, q, result);
        bool right = dfs(root->right, p, q, result);

        if ((left && right) || (self && (left || right)))
        {
            if (result == nullptr)
                result = root;
        }

        return self || left || right;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *result = nullptr;
        dfs(root, p, q, result);
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}