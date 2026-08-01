#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(vector<int> &nums, int i, int j, int p1, int p2, bool chance) // true for p1 and false for p2
    {
        if (j < i)
        {
            // we have used up all the number now p1>=p2
            return p1 >= p2;
        }
        // else we have tow cases either we can choose i_th element of j_th element
        if (chance)
        {
            // its p1's turn
            bool c1 = helper(nums, i + 1, j, p1 + nums[i], p2, false);
            bool c2 = helper(nums, i, j - 1, p1 + nums[j], p2, false);
            return c1 || c2; // if we can win in any case we will choose that branch
        }
        else
        {
            // its p2's turn
            bool c1 = helper(nums, i + 1, j, p1, p2 + nums[i], true);
            bool c2 = helper(nums, i, j - 1, p1, p2 + nums[j], true);
            return c1 && c2; // no matter what p2 does p1 should win
        }
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1, 0, 0, true);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 2};
    cout << sol.predictTheWinner(nums) << endl;
    return 0;
}