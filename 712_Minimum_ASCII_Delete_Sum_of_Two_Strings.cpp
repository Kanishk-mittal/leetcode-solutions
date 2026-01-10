#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int asciiSum(string s)
    {
        int sum = 0;
        for (char c : s)
        {
            sum += (int)c;
        }
        return sum;
    }

public:
    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = (int)s1[i] + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return asciiSum(s1) + asciiSum(s2) - (2 * dp[0][0]);
    }
};
/*
the problem can be modified to ints inverse where we can find the longest commong subsequence with highest ascii sum or in short subsequence with highest ascii sum and then we will keep that subsequence and remove all otehr characters
*/

int main()
{
    Solution sol;
    string s1 = "sea";
    string s2 = "eat";
    cout << "Minimum ASCII Delete Sum: " << sol.minimumDeleteSum(s1, s2) << endl;
    return 0;
}