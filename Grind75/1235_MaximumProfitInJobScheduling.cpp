#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     int search(vector<vector<int>> &jobs, int time)
//     {
//         int result = jobs.size();

//         int l = 0;
//         int r = jobs.size() - 1;

//         while (l <= r)
//         {
//             int mid = l + ((r - l) / 2);

//             if (jobs[mid][0] >= time)
//             {
//                 result = mid;
//                 r = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         return result;
//     }
//     int dfs(vector<int> &memo, vector<vector<int>> &jobs, int curr)
//     {
//         /*
//         jobs is a constant that gives us all the jobs in sorted order
//         end is the ending time of last event
//         curr if the current index we have to process
//         */
//         if (memo[curr] != -1)
//         {
//             return memo[curr];
//         }
//         if (curr >= jobs.size())
//         {
//             return memo[curr] = 0;
//         }
//         // case 1 we are choosing the current job
//         int c1 = jobs[curr][2] + dfs(memo, jobs, search(jobs, jobs[curr][1]));
//         int c2 = dfs(memo, jobs, curr + 1);
//         return memo[curr] = max(c1, c2);
//     }

// public:
//     int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
//     {
//         int n = startTime.size();
//         vector<vector<int>> jobs(n, vector<int>(3, 0));
//         vector<int> memo(n + 2, -1);
//         for (int i = 0; i < n; i++)
//         {
//             jobs[i][0] = startTime[i];
//             jobs[i][1] = endTime[i];
//             jobs[i][2] = profit[i];
//         }
//         sort(jobs.begin(), jobs.end());
//         return dfs(memo, jobs, 0);
//     }
// };
/*
At each step we have two options either we can choose the current one or we can leave it
if we take it next we can have is the one with start time greater than the end time of the current one
else we can continue with the next one
if we can't find any return 0;
*/

class Solution
{
private:
    int search(vector<vector<int>> &jobs, int time)
    {
        int result = jobs.size();

        int l = 0;
        int r = jobs.size() - 1;

        while (l <= r)
        {
            int mid = l + ((r - l) / 2);

            if (jobs[mid][0] >= time)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return result;
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        vector<int> dp(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        dp[n - 1] = jobs[n - 1][2];
        dp[n] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], jobs[i][2] + dp[search(jobs, jobs[i][1])]);
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    return 0;
}