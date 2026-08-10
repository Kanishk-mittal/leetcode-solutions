#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * Returns the maximum score difference (Current Player - Opponent)
     * obtainable starting from index 'idx' with current limit parameter 'm'.
     */
    int dfs(const vector<int> &piles, int idx, int m, vector<vector<int>> &dp)
    {
        int n = piles.size();
        if (idx >= n)
        {
            return 0;
        }
        if (dp[idx][m] != -1)
        {
            return dp[idx][m];
        }

        int maxDiff = -1e9;
        int currentTake = 0;

        // X is the number of piles taken in this turn, where 1 <= X <= 2 * m
        for (int x = 1; x <= 2 * m && idx + x <= n; x++)
        {
            currentTake += piles[idx + x - 1];
            // Score = (Stones taken now) - (Best difference opponent gets from remaining stones)
            int scoreDifference = currentTake - dfs(piles, idx + x, max(m, x), dp);
            maxDiff = max(maxDiff, scoreDifference);
        }

        return dp[idx][m] = maxDiff;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        // Constraints: M can grow up to n, so dp table size is n x (n + 1)
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        int maxDifference = dfs(piles, 0, 1, dp);
        int totalSum = accumulate(piles.begin(), piles.end(), 0);

        // Alice's Score = (TotalSum + MaxDifference) / 2
        return (totalSum + maxDifference) / 2;
    }
};

int main()
{
    Solution sol;
    return 0;
}