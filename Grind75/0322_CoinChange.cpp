#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &memo, vector<int> &coins, int amount, int i)
    {
        if (amount == 0)
            return 0;

        if (i >= coins.size() || amount < 0)
            return 1e9;

        if (memo[i][amount] != -1)
            return memo[i][amount];

        int take = 1 + dfs(memo, coins, amount - coins[i], i);
        int skip = dfs(memo, coins, amount, i + 1);

        return memo[i][amount] = min(take, skip);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = dfs(memo, coins, amount, 0);
        return ans >= 1e9 ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    cout << sol.coinChange(coins, 11);
    return 0;
}