# include <iostream>
# include <string>
# include <vector>
# include <stack>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode *recoverFromPreorder(string traversal)
    {
        // Convert the traversal string into pairs of (depth, value)
        vector<pair<int, int>> nodes;
        int i = 0;
        while (i < traversal.size())
        {
            int level = 0;
            // Count dashes to determine the depth
            while (i < traversal.size() && traversal[i] == '-')
            {
                level++;
                i++;
            }
            int start = i;
            // Extract the number (node value)
            while (i < traversal.size() && isdigit(traversal[i]))
            {
                i++;
            }
            int val = stoi(traversal.substr(start, i - start));
            nodes.push_back({level, val});
        }

        int index = 0; // Global index across nodes vector
        return buildTree(nodes, index, 0);
    }

private:
    // Helper function: expects the node at position 'index' to have the given 'depth'.
    TreeNode *buildTree(vector<pair<int, int>> &nodes, int &index, int depth)
    {
        // If we've processed all nodes or the current node's depth doesn't match, return nullptr.
        if (index >= nodes.size() || nodes[index].first != depth)
            return nullptr;

        // Create the current node.
        TreeNode *node = new TreeNode(nodes[index].second);
        index++; // Move to the next node in the vector.

        // Recursively build the left and right subtrees.
        node->left = buildTree(nodes, index, depth + 1);
        node->right = buildTree(nodes, index, depth + 1);
        return node;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string traversal = "1-401--349---90--88";
    TreeNode *root = s.recoverFromPreorder(traversal);
    // display dfs of the tree usign stack
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->right != nullptr)
        {
            st.push(node->right);
        }
        if (node->left != nullptr)
        {
            st.push(node->left);
        }
    }
    cout << endl;
    return 0;
}