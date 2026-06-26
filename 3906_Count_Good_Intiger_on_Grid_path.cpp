#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long dfs(string &num, vector<vector<vector<vector<int>>>> &dp, vector<int> &path, int last, int tight, int pos, int pidx)
    {
        if (pos == 16)
        {
            return pidx == 7;
        }
        if (dp[pos][last][tight][pidx] != -1)
        {
            return dp[pos][last][tight][pidx];
        }
        long long ans = 0;
        int limit = tight ? (num[pos] - '0') : 9;
        for (int d = 0; d < limit + 1; d++)
        {
            int nTight = tight && (d == limit);
            int nPidx = pidx;
            int nLast = last;
            if (pidx < 7 && pos == path[pidx])
            {
                if ((last != 10) && (d < last))
                {
                    continue;
                }
                else
                {
                    nLast = d;
                    nPidx++;
                }
            }
            ans += dfs(num, dp, path, nLast, nTight, pos + 1, nPidx);
        }
        return dp[pos][last][tight][pidx] = ans;
    }
    long long solve(long long n, vector<int> path)
    {
        if (n <= 0)
            return 0;
        // this function will find all good intiger till n
        vector<vector<vector<vector<int>>>> dp(17, vector<vector<vector<int>>>(2, vector<vector<int>>(11, vector<int>(8, -1))));
        string num = to_string(n);
        while (num.size() < 16)
        {
            num = '0' + num;
        }
        return dfs(num, dp, path, 10, 1, 0, 0);
    }

public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions)
    {
        vector<int> path(7, 0);
        int i = 1;
        for (char c : directions)
        {
            if (c == 'D')
            {
                path[i] = path[i - 1] + 4;
            }
            else
            {
                path[i] = path[i - 1] + 1;
            }
            i++;
        }
        return solve(r, path) - solve(l - 1, path);
    }
};

int main()
{
    Solution sol;
    return 0;
}