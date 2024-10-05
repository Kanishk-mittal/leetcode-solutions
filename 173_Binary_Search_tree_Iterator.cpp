#include <iostream>
#include <vector>

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

class BSTIterator
{
private:
    vector<int> nodes;
    int index;

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode *root)
    {
        index = -1;
        inorder(root);
    }

    int next()
    {
        return nodes[++index];
    }

    bool hasNext()
    {
        return index + 1 < nodes.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */