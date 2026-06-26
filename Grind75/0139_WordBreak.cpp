#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &memo, string &s, unordered_set<string> &dict, int l, int r)
    {
        // 1. BASE CASE: r goes out of range
        // If we reached the end of the string (l == s.size()), it's a success.
        if (l == s.size())
            return 1;

        // If r is out of bounds but l hasn't finished, this path failed.
        if (r > s.size())
            return 0;

        // 2. MEMO CHECK: Check after base cases to avoid index out of bounds
        if (memo[l][r] != -1)
            return memo[l][r];

        // 3. LOGIC:
        if (dict.find(s.substr(l, (r - l))) != dict.end())
        {
            // Choice 1: Use the word (Cut here, move l to r, start r at l+1)
            int r1 = dfs(memo, s, dict, r, r + 1);

            // Choice 2: Don't use the word yet (Keep expanding r)
            int r2 = dfs(memo, s, dict, l, r + 1);

            if (r1 == 1 || r2 == 1)
            {
                return memo[l][r] = 1;
            }
            else
            {
                return memo[l][r] = 0;
            }
        }
        else
        {
            // Current substring not in dict, must expand r
            return memo[l][r] = dfs(memo, s, dict, l, r + 1);
        }
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // Using unordered_set for O(1) lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        // n+1 size to accommodate r reaching s.size()
        vector<vector<int>> memo(n + 1, vector<int>(n + 2, -1));

        return dfs(memo, s, dict, 0, 1) == 1;
    }
};

int main()
{
    Solution sol;
    return 0;
}