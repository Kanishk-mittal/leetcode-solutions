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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (nullptr == root)
        {
            return result;
        }
        vector<TreeNode *> curr;
        curr.push_back(root);
        while (!curr.empty())
        {
            vector<TreeNode *> next;
            vector<int> level;
            for (TreeNode *node : curr)
            {
                level.push_back(node->val);
                if (node->left)
                {
                    next.push_back(node->left);
                }
                if (node->right)
                {
                    next.push_back(node->right);
                }
            }
            result.push_back(level);
            curr = next;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}