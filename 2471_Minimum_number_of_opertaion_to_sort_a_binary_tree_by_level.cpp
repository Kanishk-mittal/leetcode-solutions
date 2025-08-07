# include <iostream>
# include <vector>
# include <queue>
# include <unordered_map>
# include <algorithm>

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
private:
    int minSwapsInsertionSort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end()); // Get the sorted order

        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < n; ++i)
        {
            valueToIndex[nums[i]] = i; // Map values to their indices
        }

        int swaps = 0;

        for (int i = 0; i < n; ++i)
        {
            // Check if the current element is already in the correct position
            if (nums[i] != sortedNums[i])
            {
                swaps++;

                // Find the index where the current element should go
                int correctIndex = valueToIndex[sortedNums[i]];

                // Update the map with the swapped elements' new indices
                valueToIndex[nums[i]] = correctIndex;
                valueToIndex[sortedNums[i]] = i;

                // Swap the elements to place them correctly
                swap(nums[i], nums[correctIndex]);
            }
        }

        return swaps;
    }
    int numberofSwaps(vector<TreeNode*> level){
        vector<int> values;
        for(auto node: level){
            values.push_back(node->val);
        }
        return minSwapsInsertionSort(values);
    }
public:
    int minimumOperations(TreeNode *root)
    {
        vector<TreeNode *> previousLevel;
        vector<TreeNode *> currentLevel;
        int swaps = 0;
        previousLevel.push_back(root);
        while (previousLevel.size() > 0)
        {
            for (int i = 0; i < previousLevel.size(); i++)
            {
                if (previousLevel[i]->left != nullptr)
                {
                    currentLevel.push_back(previousLevel[i]->left);
                }
                if (previousLevel[i]->right != nullptr)
                {
                    currentLevel.push_back(previousLevel[i]->right);
                }
            }
            swaps += numberofSwaps(currentLevel);
            previousLevel = currentLevel;
            currentLevel.clear();
        }
        return swaps;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}