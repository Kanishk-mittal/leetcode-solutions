#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &stoneValue, int idx, vector<int> &dp)
    {
        int n = stoneValue.size();
        if (idx >= n)
            return 0;

        // Return precalculated state if available
        if (dp[idx] != -1e9)
            return dp[idx];

        int maxDiff = -1e9;
        int currentTake = 0;

        // Try picking 1, 2, or 3 stones
        for (int k = 0; k < 3 && idx + k < n; ++k)
        {
            currentTake += stoneValue[idx + k];
            // Score = (Stones I take now) - (Best difference opponent can get from remaining stones)
            int scoreDifference = currentTake - helper(stoneValue, idx + k + 1, dp);
            maxDiff = max(maxDiff, scoreDifference);
        }

        return dp[idx] = maxDiff;
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        // dp[i] stores the max score difference obtainable starting from index i
        vector<int> dp(n, -1e9);

        // Alice starts first at index 0
        int result = helper(stoneValue, 0, dp);

        if (result > 0)
            return "Alice";
        if (result < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2, 3, 7};
    vector<int> v2 = {1, 2, 3, -9};
    vector<int> v3 = {1, 2, 3, 6};
    cout << sol.stoneGameIII(v1) << endl;
    cout << sol.stoneGameIII(v2) << endl;
    cout << sol.stoneGameIII(v3) << endl;
    return 0;
}