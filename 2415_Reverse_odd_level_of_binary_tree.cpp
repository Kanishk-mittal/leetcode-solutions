# include <iostream>
# include <vector>
# include <algorithm>

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
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        /*
        Algorithm:
        1. Traverse the tree level by level.
        2. If the level is odd, store the values of the nodes in a vector.
        3. Reverse the vector.
        4. Replace the values of the nodes with the values in the vector.
        */
        if (root == nullptr)
        {
            return nullptr;
        }
        vector<TreeNode *> nodes;
        vector<int> values;
        nodes.push_back(root);
        int level = 0;
        while (!nodes.empty())
        {
            vector<TreeNode *> temp;
            int size = nodes.size();
            for (int i = 0; i < size; i++)
            {
                if (level % 2 != 0)
                {
                    values.push_back(nodes[i]->val);
                }
                if (nodes[i]->left != nullptr)
                {
                    temp.push_back(nodes[i]->left);
                }
                if (nodes[i]->right != nullptr)
                {
                    temp.push_back(nodes[i]->right);
                }
            }
            if (level % 2 != 0)
            {
                reverse(values.begin(), values.end());
                int size = nodes.size();
                for (int i = 0; i < size; i++)
                {
                    nodes[i]->val = values[i];
                }
                values.clear();
            }
            nodes = temp;
            level++;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);
    TreeNode *new_root = sol.reverseOddLevels(root);
    // print the values of the nodes in the new tree
    vector<TreeNode *> nodes;
    nodes.push_back(new_root);
    while (!nodes.empty())
    {
        vector<TreeNode *> temp;
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i]->val << " ";
            if (nodes[i]->left != nullptr)
            {
                temp.push_back(nodes[i]->left);
            }
            if (nodes[i]->right != nullptr)
            {
                temp.push_back(nodes[i]->right);
            }
        }
        cout << endl;
        nodes = temp;
    }
    return 0;
}