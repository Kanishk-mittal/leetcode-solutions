# include <iostream>
# include <vector>

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

class Solution
{
private:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &postorder, int &preIndex, int &postIndex)
    {
        TreeNode *root = new TreeNode(preorder[preIndex]);
        preIndex++;
        if (root->val != postorder[postIndex])
        {
            root->left = buildTree(preorder, postorder, preIndex, postIndex);
        }
        if (root->val != postorder[postIndex])
        {
            root->right = buildTree(preorder, postorder, preIndex, postIndex);
        }
        postIndex++;
        return root;
    }
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int preIndex = 0, postIndex = 0;
        return buildTree(preorder, postorder, preIndex, postIndex);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}