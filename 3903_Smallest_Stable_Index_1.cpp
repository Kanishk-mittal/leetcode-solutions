#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        // stoopid we can solve this by simply maintaing the minimum elelment in reverse
        int n = nums.size();
        vector<int> minArr(n);
        minArr[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            minArr[i] = min(nums[i], minArr[i + 1]);
        }
        // now we will find the solution we will get the minimum element of range i,...n-1 usign minArr[i]
        int maxVal = nums[0];
        for (int i = 0; i < n; i++)
        {
            maxVal = max(maxVal, nums[i]);
            if (maxVal - minArr[i] <= k)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    return 0;
}

/*
You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:

max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.


*/