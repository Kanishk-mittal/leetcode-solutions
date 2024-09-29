#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode *buildSubtree(const vector<int> &postorder, int postStart, int postEnd,
                           const vector<int> &inorder, int inStart, int inEnd,
                           unordered_map<int, int> &inorder_map)
    {
        // Base case: if there are no elements to process
        if (postStart > postEnd || inStart > inEnd)
        {
            return nullptr;
        }

        // The root is the first element in the current postorder segment
        int rootValue = postorder[postEnd];
        TreeNode *root = new TreeNode(rootValue);

        // Find the index of the root in the inorder traversal
        int rootIndex = inorder_map[rootValue];

        // Calculate the number of nodes in the left subtree
        int leftSize = rootIndex - inStart;

        // Recursively build the left and right subtrees
        root->left = buildSubtree(postorder, postStart, postStart + leftSize - 1,
                                  inorder, inStart, rootIndex - 1, inorder_map);
        root->right = buildSubtree(postorder, postStart + leftSize, postEnd - 1,
                                   inorder, rootIndex + 1, inEnd, inorder_map);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorder_map[inorder[i]] = i;
        }

        // Helper function to recursively build the tree
        return buildSubtree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }
};
