#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int n = nums[0];
        for (int x : nums)
        {
            n = max(n, x);
        }
        n++;
        vector<int> freq(n, -1);
        freq[0] = 0;
        freq[n - 1] = -2;
        for (int x : nums)
        {
            freq[x]++;
        }
        for (int x : freq)
        {
            if (x != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 3, 2};
    cout << sol.isGood(nums) << endl;
    return 0;
}