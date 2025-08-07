# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
            { return a[0] < b[0]; });

        vector<vector<int>> res;
        res.push_back(intervals[0]); // Start with the first interval

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                // Merge intervals if overlapping
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                // Add new interval
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};