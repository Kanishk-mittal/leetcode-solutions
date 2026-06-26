#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // we can go with multipoint bfs
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q; // {i,j,h}
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({i, j, 0});
                }
            }
        }
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty())
        {
            vector<int> t = q.front();
            q.pop();
            int x = t[0];
            int y = t[1];
            int h = t[2];
            mat[x][y] = h;
            for (pair<int, int> c : dirs)
            {
                int newX = x + c.first;
                int newY = y + c.second;
                if ((newX >= 0 && newX < m) && (newY >= 0 && newY < n) && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    q.push({newX, newY, h + 1});
                }
            }
        }
        return mat;
    }
};

int main()
{
    Solution sol;

    return 0;
}