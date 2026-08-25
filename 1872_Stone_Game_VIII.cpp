#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int stoneGameVIII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> prefix(n, stones[0]);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = stones[i] + prefix[i - 1];
        }
        vector<int> dp(n, 0);
        dp[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], prefix[i] - dp[i + 1]);
        }
        return dp[1];
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();