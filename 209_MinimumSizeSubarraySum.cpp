#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0;
        int n = nums.size();
        int fullSum = 0;
        int sum = 0;
        int result = n;
        for (int r = 0; r < n; r++)
        {
            sum += nums[r];
            fullSum += nums[r];
            while (l <= r && sum >= target)
            {
                result = min(result, (r - l) + 1);
                sum -= nums[l];
                l++;
            }
        }
        return fullSum >= target ? result : 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums);
    return 0;
}