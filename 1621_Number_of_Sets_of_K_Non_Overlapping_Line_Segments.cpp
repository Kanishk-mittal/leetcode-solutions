#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
class Solution
{
private:
    int helper(vector<vector<int>> &memo, int n, int k)
    {
        if (memo[n][k] != -1)
        {
            return memo[n][k];
        }
        if (k <= 0)
        {
            return 1;
        }
        if (n <= 0)
        {
            return 0;
        }
        if (k >= n)
        {
            return 0;
        }
        if (k == n - 1)
        {
            return 1;
        }
        long long total = 0;
        // we skip the current point entirely
        total += helper(memo, n - 1, k);
        for (int i = 1; i <= n - k; i++)
        {
            // lets say the lenght of first line is i
            total += helper(memo, n - i, k - 1);
        }
        return memo[n][k] = (total % MOD);
    }

public:
    int numberOfSets(int n, int k)
    {
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        return helper(memo, n, k);
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.numberOfSets(3,2)<<endl;
    return 0;
}
