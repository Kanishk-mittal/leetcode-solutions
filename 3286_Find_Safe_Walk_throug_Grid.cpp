#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> healthArr(m, vector<int>(n, -1));
        healthArr[0][0] = health - grid[0][0];
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<pair<int, int>> dirs = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
        };
        bool found = false;
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            if (curr.first == m - 1 && curr.second == n - 1 && healthArr[m - 1][n - 1] >= 1)
            {
                found = true;
                break;
            }
            for (pair<int, int> dir : dirs)
            {
                int nx = curr.first + dir.first;
                int ny = curr.second + dir.second;
                if (
                    (nx >= 0 && nx < m) &&
                    (ny >= 0 && ny < n))
                {
                    int nh = healthArr[curr.first][curr.second] - grid[nx][ny];
                    if (nh >= 1 && nh > healthArr[nx][ny])
                    {
                        q.push({nx, ny});
                        healthArr[nx][ny] = nh;
                    }
                }
            }
        }
        return found;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0}};
    cout << sol.findSafeWalk(grid, 3);
    return 0;
}