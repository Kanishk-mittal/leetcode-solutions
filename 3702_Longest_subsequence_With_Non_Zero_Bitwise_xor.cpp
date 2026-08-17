#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int XOR = 0;
        bool allZero = true;
        for (int i : nums)
        {
            XOR ^= i;
            if (i != 0)
            {
                allZero = false;
            }
        }
        if (allZero)
        {
            return 0;
        }
        if (XOR)
        {
            return nums.size();
        }
        else
        {
            return nums.size() - 1;
        }
    }
};

int main()
{
    Solution sol;
    return 0;
}