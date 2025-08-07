#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        int longest = 1;
        int lastnumber = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == lastnumber)
            {
                cnt += 1;
                lastnumber = nums[i];
            }
            else if (lastnumber != nums[i])
            {
                cnt = 1;
                lastnumber = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};