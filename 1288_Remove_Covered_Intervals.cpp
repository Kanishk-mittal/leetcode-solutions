#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
                if (a[0] == b[0])
                {
                    return a[1]>b[1];
                }else{
                    return a[0]<b[0];
                } });
        int count = 0;
        int n = intervals.size();
        int end = intervals[0][1];
        for (int i = 0; i < n; i++)
        {
            count++;
            while (i < n && intervals[i][1] <= end)
            {
                i++;
            }
            if (i < n)
            {
                end = intervals[i][1];
                i--;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {
        {0, 10},
        {5, 12},
    };
    cout << sol.removeCoveredIntervals(intervals) << endl;
    return 0;
}