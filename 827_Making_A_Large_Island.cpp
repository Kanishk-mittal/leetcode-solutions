#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int x, int y, int color, vector<int> &color_vector, vector<vector<int>> &directions, int n)
    {
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0 || color_vector[x * n + y] != -1)
        {
            return 0;
        }

        color_vector[x * n + y] = color; // Assign color ID
        int size = 1;

        for (vector<int> &dir : directions)
        {
            size += dfs(grid, x + dir[0], y + dir[1], color, color_vector, directions, n);
        }

        return size;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> color_vector(n * n, -1); // Marking colors for each cell
        vector<int> componentSize;           // Stores size of each component
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int max_color = 0;

        // 1. Identify all connected components and assign unique colors
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && color_vector[i * n + j] == -1)
                {
                    componentSize.push_back(dfs(grid, i, j, max_color, color_vector, directions, n));
                    max_color++;
                }
            }
        }

        // If the whole grid is 1, return n*n
        if (componentSize.empty())
            return 1;
        int max_size = *max_element(componentSize.begin(), componentSize.end());

        // 2. Try flipping each zero and compute max possible island size
        bool zero_found = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    zero_found = true;
                    int size = 1;
                    unordered_set<int> unique_colors;

                    for (vector<int> &dir : directions)
                    {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            unique_colors.insert(color_vector[x * n + y]);
                        }
                    }

                    for (int c : unique_colors)
                    {
                        size += componentSize[c];
                    }

                    max_size = max(max_size, size);
                }
            }
        }

        return zero_found ? max_size : n * n;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << sol.largestIsland(grid) << endl; // Expected output: 3

    return 0;
}
