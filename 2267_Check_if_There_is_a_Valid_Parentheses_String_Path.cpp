#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkSub(vector<vector<vector<int>>> &memo, vector<vector<char>> &grid, int i, int j, int offSet)
    {
        
        if (i == grid.size() - 1 && j == grid[0].size()-1)
        {
            if (grid[i][j] == '(')
            {
                offSet++;
            }
            else
            {
                offSet--;
            }
            return offSet==0;
        }
        if (i >= grid.size() || j >= grid[0].size())
        {
            return false;
        }
        if (grid[i][j] == '(')
        {
            offSet++;
        }
        else
        {
            offSet--;
        }
        if (offSet < 0)
        {
            return false; // offset can never go negative;
        }
        if (memo[i][j][offSet]!=-1)
        {
            return memo[i][j][offSet];
        }
        return memo[i][j][offSet] = (checkSub(memo, grid, i, j + 1, offSet) || checkSub(memo, grid, i + 1, j, offSet));
    }

public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(m + n + 2, -1)));
        return checkSub(memo, grid, 0, 0, 0);
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();