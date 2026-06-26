#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &memo, vector<int> &nums, int target, int idx)
    {
        // base cases
        if (target == 0)
        {
            return memo[target][idx] = 1;
        }
        if (idx >= nums.size())
        {
            return memo[target][idx] = 0;
        }

        // memo check
        if (memo[target][idx] != -1)
        {
            return memo[target][idx];
        }

        // choice 1: skip current element
        int r1 = dfs(memo, nums, target, idx + 1);

        // choice 2: take current element (ONLY if valid)
        int r2 = 0;
        if (target >= nums[idx])
        {
            r2 = dfs(memo, nums, target - nums[idx], idx + 1);
        }

        return memo[target][idx] = (r1 || r2);
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }

        // if total sum is odd → impossible
        if (sum & 1)
        {
            return false;
        }

        int target = sum / 2;

        // memo[target][idx]
        vector<vector<int>> memo(target + 1, vector<int>(n + 1, -1));

        return dfs(memo, nums, target, 0);
    }
};

int main()
{
    Solution sol;
    return 0;
}