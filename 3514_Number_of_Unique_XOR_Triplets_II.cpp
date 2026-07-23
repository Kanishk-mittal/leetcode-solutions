#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        // since nums[i]<=1500 the maximum possible XOR of any three number can be never be larger that 2047 (2048-1)
        vector<bool> pairXOR(2048, false);
        for (int i : nums)
        {
            for (int j : nums)
            {
                pairXOR[i ^ j] = true;
            }
        }
        vector<bool> result(2048, false);
        for (int i : nums)
        {
            for (int j = 0; j < 2048; j++)
            {
                if (pairXOR[j])
                {
                    result[i ^ j] = true;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 2048; i++)
        {
            count += result[i];
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {6, 7, 8, 9};
    cout << sol.uniqueXorTriplets(nums);
    return 0;
}