#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * helper function to implement memoization
     *
     * @param n value for which we need to check
     * @param memo memoization vector to hold previously seen values
     * @return true if we can win else false
     */
    bool helper(int n, vector<int> &memo)
    {
        if (memo[n] != -1)
        {
            return memo[n];
        }

        // try picking all perfect square
        for (int i = 1; i * i <= n; i++)
        {
            bool temp = helper(n - i * i, memo);
            if (!temp)
            {
                // the other player will loose in this scenario
                memo[n] = true;
                return true;
            }
        }
        // there is no way we can win
        memo[n] = false;
        return false;
    }

public:
    bool winnerSquareGame(int n)
    {
        vector<int> memo(n + 1, -1); // -1 not visited , 1  true, 0 false
        memo[0] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            memo[i * i] = 1; // we will win if the input is a perfect square
        }
        return helper(n, memo);
    }
};

int main()
{
    Solution sol;
    cout << sol.winnerSquareGame(2) << endl;
    return 0;
}