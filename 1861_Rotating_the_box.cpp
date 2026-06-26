#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.'));
        for (int r = 0; r < m; r++)
        {
            int emptyPos = n - 1;
            for (int c = n - 1; c >= 0; c--)
            {
                if ('#' == boxGrid[r][c])
                {
                    result[emptyPos][m - r - 1] = '#';
                    emptyPos--;
                    continue;
                }
                if ('*' == boxGrid[r][c])
                {
                    result[c][m - r - 1] = '*';
                    emptyPos = c - 1;
                    continue;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}