#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;

        // Count fresh oranges and add rotten oranges to the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    freshCount++;
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshCount == 0)
        {
            return 0;
        }

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int level = 0;

        while (!q.empty())
        {
            int s = q.size();
            bool rotted = false;

            for (int i = 0; i < s; i++)
            {
                pair<int, int> t = q.front();
                q.pop();

                for (pair<int, int> d : dirs)
                {
                    int nx = t.first + d.first;
                    int ny = t.second + d.second;

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1)
                    {
                        continue;
                    }

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    freshCount--;
                    rotted = true;
                }
            }

            if (rotted)
            {
                level++;
            }
        }

        // If there are still fresh oranges, return -1
        return freshCount == 0 ? level : -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}