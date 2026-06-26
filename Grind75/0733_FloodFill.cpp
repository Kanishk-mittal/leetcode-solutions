#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color)
        {
            return image; // No need to fill if the original color is the same as the new color
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[sr][sc] = true;
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            image[r][c] = color; // Fill the current pixel with the new color
            for (const auto &dir : directions)
            {
                int newRow = r + dir[0];
                int newCol = c + dir[1];
                // Check if the new position is within bounds and has the original color
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    !visited[newRow][newCol] && image[newRow][newCol] == originalColor)
                {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};

int main()
{
    Solution sol;
    return 0;
}