#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end())
            {
                return {mp[compliment], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution sol;
    return 0;
}