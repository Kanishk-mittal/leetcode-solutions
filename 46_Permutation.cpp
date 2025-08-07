# include <iostream>
# include <vector>
# include <algorithm>   

using namespace std;

class Solution
{
private:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, int index)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(result, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }
};