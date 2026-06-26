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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> mp;
        unordered_set<int> st;
        for (auto &d : descriptions)
        {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);
            if (mp.find(child) == mp.end())
                mp[child] = new TreeNode(child);
            st.insert(child);
            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];
        }
        for (auto &p : mp)
        {
            if (st.find(p.first) == st.end())
                return p.second;
        }
        return nullptr;
    }
};

int main()
{
    Solution sol;
    return 0;
}