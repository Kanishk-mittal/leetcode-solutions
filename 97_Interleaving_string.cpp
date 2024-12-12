#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        int n = s1.size();
        int m = s2.size();

        // Initialize the DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case
        dp[n][m] = true;

        // Fill the DP table from bottom-right to top-left
        for (int i = n; i >= 0; i--)
        {
            for (int j = m; j >= 0; j--)
            {
                if (i < n && s1[i] == s3[i + j] && dp[i + 1][j])
                {
                    dp[i][j] = true;
                }
                if (j < m && s2[j] == s3[i + j] && dp[i][j + 1])
                {
                    dp[i][j] = true;
                }
            }
        }

        // Result is in the top-left corner
        return dp[0][0];
    }
};

int main()
{
    Solution solution;
    string s1 = "aab";
    string s2 = "axy";
    string s3 = "aaxaby";

    cout << boolalpha << solution.isInterleave(s1, s2, s3) << endl;

    return 0;
}
