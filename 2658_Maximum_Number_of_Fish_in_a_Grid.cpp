# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &directions)
    {
        int m = grid.size(), n = grid[0].size();
        int fish = grid[x][y];
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];
            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] > 0)
            {
                fish += dfs(grid, new_x, new_y, directions);
            }
        }
        return fish;
    }
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        int max_fish = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                {
                    max_fish = max(max_fish, dfs(grid, i, j, directions));
                }
            }
        }
        return max_fish;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}