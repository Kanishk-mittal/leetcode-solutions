#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        long long MOD = 1e9 + 7;
        int n = s.size();

        // 1. Precompute powers of 10 modulo 1e9+7
        vector<long long> pow10(n + 1, 1);
        for (int i = 0; i < n; i++)
        {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> sumPrefix(n + 1, 0);
        vector<long long> numPrefix(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0); // 2. Track non-zero digits

        for (int i = 0; i < n; i++)
        {
            int digit = s[i] - '0';

            sumPrefix[i + 1] = sumPrefix[i] + digit;
            nonZeroCount[i + 1] = nonZeroCount[i] + (digit > 0 ? 1 : 0);

            if (digit == 0)
            {
                numPrefix[i + 1] = numPrefix[i];
            }
            else
            {
                numPrefix[i + 1] = ((numPrefix[i] * 10) + digit) % MOD;
            }
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            long long digitSum = sumPrefix[r + 1] - sumPrefix[l];

            // Calculate how many non-zero digits are in this specific range
            int c = nonZeroCount[r + 1] - nonZeroCount[l];

            // Shift numPrefix[l] to the left by 'c' places
            long long subtract = (numPrefix[l] * pow10[c]) % MOD;

            // Calculate the valid number formed by the non-zero digits in range [l, r]
            long long number = (numPrefix[r + 1] - subtract + MOD) % MOD;

            result[i] = (digitSum * number) % MOD;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "10203004";
    vector<vector<int>> queries = {{0, 7},
                                   {1, 3},
                                   {4, 6}};
    vector<int> result = sol.sumAndMultiply(s, queries);
    for (int res : result)
    {
        cout << res << endl;
    }
    return 0;
}