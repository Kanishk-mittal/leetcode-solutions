#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int row = 0;
        int col = grid[0].size() - 1;
        int result = 0;
        while (row < grid.size())
        {
            while (col >= 0 && grid[row][col] < 0)
            {
                col--;
            }
            result += grid[0].size() - col - 1;
            col = min(col, (int)grid[0].size() - 1);
            row++;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{3, 2}, {1, 0}};
    cout << sol.countNegatives(grid) << endl; // Output:0
    return 0;
}