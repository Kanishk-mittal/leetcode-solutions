#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        int visited = 0;

        // Initialize the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    isWater[i][j] = 0; // Water cells start with height 0
                    q.push({i, j});    // Add water cells to the queue
                    visited++;
                }
                else
                {
                    isWater[i][j] = -1; // Land cells are unvisited
                }
            }
        }

        // Multi-source BFS
        while (!q.empty() && visited <= m * n)
        {
            auto [x, y] = q.front();
            q.pop();
            for (const auto &dir : dirs)
            {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && isWater[nx][ny] == -1)
                {
                    isWater[nx][ny] = isWater[x][y] + 1; // Set height
                    q.push({nx, ny});
                    visited++;
                }
            }
        }
        return isWater;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    vector<vector<int>> result = solution.highestPeak(isWater);

    for (const auto &row : result)
    {
        for (int height : row)
        {
            cout << height << " ";
        }
        cout << endl;
    }
    return 0;
}
