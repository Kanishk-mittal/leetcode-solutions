#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int l = intervals[0][0];
        int r = intervals[0][1];
        vector<vector<int>> result;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= r)
            {
                r = max(r, intervals[i][1]);
            }
            else
            {
                result.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        result.push_back({l, r});
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 4}, {4, 8}};
    // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.merge(intervals);
    for (vector<int> &i : result)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}