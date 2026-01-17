#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        // for each square find all overlaping square and find using that
        int n = bottomLeft.size();
        int side = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                int overlapX = min(topRight[j][0], topRight[i][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int overlapY = min(topRight[j][1], topRight[i][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                {
                    side = max(side, min(overlapX, overlapY));
                }
            }
        }
        return 1LL * side * side;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> topRight = {{3, 3}, {4, 4}, {6, 6}};
    cout << sol.largestSquareArea(bottomLeft, topRight) << endl;
    return 0;
}