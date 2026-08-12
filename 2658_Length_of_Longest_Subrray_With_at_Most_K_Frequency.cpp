#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int r = 0;
        int result = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int l = 0; l < n; l++)
        {
            while (r < n && freq[nums[r]] < k)
            {
                freq[nums[r]]++;
                r++;
            }
            result = max(result, r - l);
            freq[nums[l]]--;
        }
        return result;
    }
};

int main()
{
    Solution sol;

    return 0;
}