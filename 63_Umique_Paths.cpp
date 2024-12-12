# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int getValue(vector<vector<int>> &dp, int i, int j)
    {
        // this will return the sum of values of top and left cell
        int top = i - 1 >= 0 ? dp[i - 1][j] : 0;
        int left = j - 1 >= 0 ? dp[i][j - 1] : 0;
        return top + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i != 0 || j != 0)
                { // Skip the start cell
                    dp[i][j] = getValue(dp, i, j);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}