#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }
        return minDiff;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {9, 4, 1, 7};
    int k = 2;
    cout << sol.minimumDifference(nums, k) << endl; // Output: 2
    return 0;
}