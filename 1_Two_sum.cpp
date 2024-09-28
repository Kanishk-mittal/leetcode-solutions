#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<int> index_of(int num1, int num2, vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1 || nums[i] == num2)
            {
                result.push_back(i);
            }
        }
        return result;
    }

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.find(target - nums[i]) != set.end())
            {
                return index_of(nums[i], target - nums[i], nums);
            }
            set.insert(nums[i]);
        }
        return {};
    }
};