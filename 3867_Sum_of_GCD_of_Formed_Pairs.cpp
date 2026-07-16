#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        int mx = nums[0];
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            nums[i] = gcd(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            sum += gcd(nums[i], nums[n - i - 1]);
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 6, 4};
    cout << sol.gcdSum(nums);
    return 0;
}