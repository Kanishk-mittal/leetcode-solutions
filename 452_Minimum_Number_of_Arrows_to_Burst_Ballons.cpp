# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution  
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
            { return a[0] < b[0]; });
        int start = points[0][0];
        int end = points[0][1];
        int count = 1;
        for (auto point : points)
        {
            if (point[0] <= end)
            {
                end = min(point[1], end);
            }
            else
            {
                start = point[0];
                end = point[1];
                count++;
            }
        }
        return count;
    }
};