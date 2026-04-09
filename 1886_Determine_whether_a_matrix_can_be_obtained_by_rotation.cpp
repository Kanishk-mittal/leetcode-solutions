#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
private:
    void rotate90(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                rotated[j][n - 1 - i] = mat[i][j];
            }
        }
        mat = rotated;
    }

public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        // rotate mat 4 times and check if it matches target
        for (int i = 0; i < 4; ++i)
        {
            if (mat == target)
            {
                return true;
            }
            rotate90(mat);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    cout << sol.findRotation(mat, target) << endl; // Output: true
    return 0;
}