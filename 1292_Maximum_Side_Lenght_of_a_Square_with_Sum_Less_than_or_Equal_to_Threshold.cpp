#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getSum(vector<vector<int>> &mat, int k, int x, int y)
    {
        int sum = 0;
        for (int i = x; i < x + k; i++)
        {
            for (int j = y; j < y + k; j++)
            {
                sum += mat[i][j];
            }
        }
        return sum;
    }

public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int k = min(m, n) - 1; k >= 0; k--)
        {
            for (int i = 0; i < m - k; i++)
            {
                for (int j = 0; j < n - k; j++)
                {
                    if (getSum(mat, k, i, j) <= threshold)
                    {
                        return k;
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
    vector<vector<int>> mat = {{1, 1, 3, 2, 4, 3, 2},
                               {1, 1, 3, 2, 4, 3, 2},
                               {1, 1, 3, 2, 4, 3, 2}};
    int threshold = 4;
    cout << sol.maxSideLength(mat, threshold) << endl;
    return 0;
}