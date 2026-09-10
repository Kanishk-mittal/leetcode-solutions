#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    /**
     * helper function for finding average
     *
     * @param root current node 
     * @param count this is the result will update it as we traverse the tree
     * @return {count, sum} returns the count of element and their sum of the current subtree
     */
    pair<int,int> helper(TreeNode* root, int& count){
        if (root->left==nullptr && root->right == nullptr)
        {
            count++;
            return {1,root->val};
        }
        int nodeCount=1;
        int sum=root->val;
        if (root->left)
        {
            pair<int,int> result = helper(root->left,count);
            nodeCount+=result.first;
            sum+=result.second;
        }
        if (root->right)
        {
            pair<int,int> result = helper(root->right,count);
            nodeCount+=result.first;
            sum+=result.second;
        }
        if ((sum/nodeCount)==root->val)
        {
            count++;
        }
        return {nodeCount,sum};        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count =0;
        helper(root,count);
        return count;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();