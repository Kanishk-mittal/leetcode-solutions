#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     int dfs(vector<vector<int>> &memo, vector<int> &nums, int target, int lastStop, int i)
//     {
//         // either we can have a stop at i or we can skip it
//         if (-2 != memo[i][lastStop])
//         {
//             return memo[i][lastStop];
//         }
//         if (i == (nums.size() - 1))
//         {
//             int diff = abs(nums[i] - nums[lastStop]);
//             return memo[i][lastStop] = (diff <= target ? 1 : -1);
//         }
//         int c1 = dfs(memo, nums, target, lastStop, i + 1);
//         int c2 = -1;
//         if (abs(nums[i] - nums[lastStop]) <= target)
//         {
//             c2 = dfs(memo, nums, target, i, i + 1);
//         }
//         int result = -1;
//         if (-1 != c1)
//         {
//             result = max(result, c1);
//         }
//         if (-1 != c2)
//         {
//             result = max(result, 1 + c2);
//         }
//         return memo[i][lastStop] = result;
//     }

// public:
//     int maximumJumps(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         vector<vector<int>> memo(n, vector<int>(n, -2));
//         return dfs(memo, nums, target, 0, 1);
//     }
// };

// lets try iterative solution now
class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // base case
        for (int last = 0; last < n; last++)
        {
            if (abs(nums[n - 1] - nums[last]) <= target)
                dp[n - 1][last] = 1;
        }

        for (int i = n - 2; i >= 1; i--)
        {
            for (int last = 0; last < i; last++)
            {
                // skip
                int ans = dp[i + 1][last];

                // take
                if (abs(nums[i] - nums[last]) <= target &&
                    dp[i + 1][i] != -1)
                {
                    ans = max(ans, 1 + dp[i + 1][i]);
                }

                dp[i][last] = ans;
            }
        }

        return dp[1][0];
    }
};

/*
we can only move forward
maximum possible answer is nums.size();
looks like a dp question
possible choices for us
    1.if possible end the jump at current index or we can continue flying

*/

/*
we can only move forward
maximum possible answer is nums.size();
looks like a dp question
possible choices for us
    1.if possible end the jump at current index or we can continue flying

*/

int main()
{
    Solution sol;
    vector<int> nums = {
        1,
        3,
        6,
        4,
        1,
        2};
    cout << sol.maximumJumps(nums, 2);
    return 0;
}