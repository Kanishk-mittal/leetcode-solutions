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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (nullptr == root)
        {
            return "#";
        }
        string result = "";
        result.append(serialize(root->left));
        result.append(to_string(root->val));
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
    }
};

int main()
{
    Solution sol;
    return 0;
}