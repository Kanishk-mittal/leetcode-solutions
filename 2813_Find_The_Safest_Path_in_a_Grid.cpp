#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Multi-point BFS to find the distance to the nearest thief
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    grid[i][j] = 0; // Distance to thief is 0
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (pair<int, int> dir : dirs)
            {
                int ni = curr.first + dir.first;
                int nj = curr.second + dir.second;
                if ((ni >= 0 && ni < m) && (nj >= 0 && nj < n) && (!visited[ni][nj]))
                {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                    grid[ni][nj] = grid[curr.first][curr.second] + 1;
                }
            }
        }

        // Weighted BFS (Dijkstra-like with Max Heap) to find the safest path
        priority_queue<vector<int>> pq; // {safeness_factor, x, y}
        pq.push({grid[0][0], 0, 0});

        // OPTIMIZATION: State tracking array to prevent PQ bloat.
        // Initialize with -1 to represent unvisited/worst possible safeness.
        vector<vector<int>> max_safeness(m, vector<int>(n, -1));
        max_safeness[0][0] = grid[0][0];

        while (!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();

            int safeness = curr[0];
            int r = curr[1];
            int c = curr[2];

            // Early exit. If we pop the destination, we found the optimal path.
            if (r == m - 1 && c == n - 1)
            {
                return safeness;
            }

            // If we already found a better path to this cell before popping it, skip it.
            if (safeness < max_safeness[r][c])
            {
                continue;
            }

            for (pair<int, int> dir : dirs)
            {
                int ni = r + dir.first;
                int nj = c + dir.second;

                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    int new_safe = min(safeness, grid[ni][nj]);

                    // Push ONLY if this path offers a strictly better safeness factor
                    if (new_safe > max_safeness[ni][nj])
                    {
                        max_safeness[ni][nj] = new_safe; // Update the best seen immediately
                        pq.push({new_safe, ni, nj});
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0}};
    sol.maximumSafenessFactor(grid);
    return 0;
}