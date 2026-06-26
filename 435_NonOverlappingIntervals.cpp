#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<pair<int, int>> dp(n, {-1, -1});
        sort(intervals.begin(), intervals.end());
        int r = intervals[n - 1][0];
        dp[n - 1].first = 0;
        dp[n - 1].second = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (intervals[i][1] > r)
            {
                // here we have an overlap
                dp[i].first = dp[i + 1].second;
                dp[i].second = 1 + min(dp[i + 1].first, dp[i + 1].first);
            }
            else
            {
                int temp = min(dp[i + 1].first, dp[i + 1].second);
                dp[i].first = temp;
                dp[i].second = temp + 1;
            }
            r = min(r, intervals[i][0]);
        }
        return min(dp[0].first, dp[0].second);
    }
};

/*
Can be a DP problem two states either we can keep it or remove it if we keep it then we can non take any overlaping interval
dp[i][0] -> gives us the minimum number of intervals needed to be removed from i . . . n considering we keep the current one
dp[i][1] -> gives us the minimum number of intervals needed to be removed from i . . . n considering we remove the current one
dp[n-1][0] -> 0 as we have just one element
dp[n-1][1] -> 1 as we have removed one element
max(dp[0][1],dp[0][0]) -> this gives us the answer
dp[i][0] -> if intervals[i] and intervals[i+1] overlaps then dp[i][0]=dp[i+1][1] and dp[i][1]=1+max(dp[i+1][0],dp[i+1][0]);
            else in case of no overlaps then dp[i][0]=max(dp[i+1][0],dp[i+1][0]) and dp[i][1]=1+max(dp[i+1][0],dp[i+1][0])
*/

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {
        {1, 2},
        {1, 2},
        {1, 2}};
    cout << sol.eraseOverlapIntervals(intervals) << "\n";
    return 0;
}
