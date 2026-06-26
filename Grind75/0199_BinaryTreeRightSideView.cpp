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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }
        vector<TreeNode *> q;
        q.push_back(root);
        while (!q.empty())
        {
            res.push_back(q.back()->val);
            vector<TreeNode *> temp;
            for (int i = 0; i < q.size(); i++)
            {
                if (q[i]->left != NULL)
                {
                    temp.push_back(q[i]->left);
                }
                if (q[i]->right != NULL)
                {
                    temp.push_back(q[i]->right);
                }
            }
            q = temp;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    return 0;
}