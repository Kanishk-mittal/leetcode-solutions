#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> flat;
        flat.reserve(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                flat.push_back(grid[i][j]);
            }
        }
        sort(flat.begin(), flat.end());
        int median = flat[(m * n) / 2];
        // now we will try to convert all elements to median
        int opCount = 0;
        for (int i = 0; i < m * n; i++)
        {
            int diff = abs(flat[i] - median);
            if (diff % x != 0)
            {
                return -1;
            }
            opCount += (int)(diff / x);
        }
        return opCount;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    cout << sol.minOperations(grid, 2) << endl; // Output: 2
    return 0;
}