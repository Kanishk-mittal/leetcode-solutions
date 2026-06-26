#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> &nums, vector<int> &current, vector<vector<int>> &result, vector<bool> &used, int remaining)
    {
        if (0 == remaining)
        {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            current.push_back(nums[i]);
            used[i] = true;
            dfs(nums, current, result, used, remaining - 1);
            used[i] = false;
            current.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<vector<int>> result;
        vector<int> current;
        dfs(nums, current, result, used, n);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> result = sol.permute(nums);
    for (auto &v : result)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}