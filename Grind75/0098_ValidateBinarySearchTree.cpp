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
    bool dfs(TreeNode *root, long long l, long long r)
    {
        if (nullptr == root)
        {
            return true;
        }
        if (root->val >= r || root->val <= l)
        {
            return false;
        }
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, 1LL * INT_MIN - 1LL, 1LL * INT_MAX + 1LL);
    }
};

int main()
{
    Solution sol;
    return 0;
}