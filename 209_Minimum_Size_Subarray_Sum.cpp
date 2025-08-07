# include <iostream>
# include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int n = nums.size();
        int min_len = n + 1;

        while (right < n)
        {
            sum += nums[right];
            while (sum >= target)
            {
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return (min_len == n + 1) ? 0 : min_len;
    }
};