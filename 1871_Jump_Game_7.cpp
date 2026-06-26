#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        if (s[n - 1] != '0')
        {
            return false;
        }
        // we can use sliding window in backward direction as well
        // window size is maxJump-minJump+1
        int windowSize = (maxJump - minJump) + 1;
        // value at index i depends on window (i+minJump and i=maxJump)
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        int temp = 1;           // this is out last inded
        int currWindowSize = 1; // currently we have only on element
        int l = n - 1;
        int r = n - 1;
        for (int i = n - minJump; i >= 0; i--)
        {
            // check for current one
            if ('0' == s[i] && temp)
            {
                dp[i] = true;
            }
            // expand the window
            temp += dp[l - 1]
        }
    }
};

int main()
{
    Solution sol;
    return 0;
}