# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        dp[0][0] = 0;
        vector<vector<int>> q = {{0, 0}};
        while (!q.empty())
        {
            vector<vector<int>> newQ;
            for (auto &p : q)
            {
                int x = p[0], y = p[1];
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dirs[i][0], ny = y + dirs[i][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        int cost = grid[x][y] != i + 1;
                        if (dp[x][y] + cost < dp[nx][ny])
                        {
                            dp[nx][ny] = dp[x][y] + cost;
                            newQ.push_back({nx, ny});
                        }
                    }
                }
            }
            q = newQ;
        }
        return dp[n - 1][m - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}