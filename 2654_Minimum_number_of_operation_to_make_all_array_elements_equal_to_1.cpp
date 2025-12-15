#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
private:
    int gcdArr(vector<int> &nums, int start, int end)
    {
        if (start == end - 1)
        {
            return gcd(nums[start], nums[start + 1]);
        }
        return gcd(nums[start], gcdArr(nums, start + 1, end));
    }

public:
    int minOperations(vector<int> &nums)
    {
        // find smallest subarray with gcd == 1
        int minSize = INT_MAX;
        int oneCount = 0;
        if (gcdArr(nums, 0, nums.size() - 1) != 1)
        {
            return -1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                oneCount++;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                int GCD = gcdArr(nums, i, j);
                if (GCD == 1)
                {
                    minSize = min(minSize, j - i + 1);
                }
            }
        }
        if (oneCount == nums.size())
        {
            return 0;
        }
        if (minSize == 2)
        {
            return nums.size() - oneCount;
        }
        return nums.size() - oneCount + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 5, 10, 30, 70, 4, 2, 6, 8, 4};
    cout << sol.minOperations(nums) << endl; // Output: 4
    return 0;
}