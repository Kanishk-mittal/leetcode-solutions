#include <iostream>
#include <vector>
#include <unordered_set>

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

class FindElements
{
private:
    unordered_set<int> values; // Store recovered values for fast lookup

    void recoverTree(TreeNode *root, int val)
    {
        if (root == nullptr)
            return;

        root->val = val;
        values.insert(val);

        if (root->left != nullptr)
            recoverTree(root->left, 2 * val + 1);
        if (root->right != nullptr)
            recoverTree(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode *root)
    {
        if (root)
            recoverTree(root, 0); // Recover tree starting from root with value 0
    }

    bool find(int target)
    {
        return values.find(target) != values.end(); // O(1) lookup
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main()
{
    TreeNode *root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);

    FindElements *obj = new FindElements(root);

    cout << obj->find(1) << endl; // Expected output: 1 (true)
    cout << obj->find(2) << endl; // Expected output: 1 (true)
    cout << obj->find(3) << endl; // Expected output: 1 (true)
    cout << obj->find(4) << endl; // Expected output: 0 (false)

    delete obj;
    return 0;
}
