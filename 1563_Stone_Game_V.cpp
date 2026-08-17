#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<vector<int>> &memo, vector<int> &prefixSum, int l, int r)
    {
        if (l >= r - 1)
            return 0; // Range of size 1 or less yields 0 score
        if (memo[l][r] != -1)
            return memo[l][r];

        int total = prefixSum[r] - prefixSum[l];
        int prefix = 0;
        int result = 0;

        for (int i = l; i < r - 1; i++)
        {
            prefix = prefixSum[i + 1] - prefixSum[l];
            int suffix = total - prefix;

            if (prefix < suffix)
            {
                // Left side is strictly smaller: Alice takes left side
                result = max(result, prefix + helper(memo, prefixSum, l, i + 1));
            }
            else if (prefix > suffix)
            {
                // Right side is strictly smaller: Alice takes right side
                result = max(result, suffix + helper(memo, prefixSum, i + 1, r));
            }
            else
            {
                // Equal sides: Alice can choose either side to maximize score
                result = max(result, prefix + helper(memo, prefixSum, l, i + 1));
                result = max(result, suffix + helper(memo, prefixSum, i + 1, r));
            }
        }
        return memo[l][r] = result;
    }

public:
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return helper(memo, prefixSum, 0, n);
    }
};

int main()
{
    Solution sol;
    return 0;
}