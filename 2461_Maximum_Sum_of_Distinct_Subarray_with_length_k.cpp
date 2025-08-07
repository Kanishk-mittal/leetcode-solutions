#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long max_sum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            freq[nums[right]]++;
            sum += nums[right];

            // Maintain unique elements by moving left pointer if a duplicate is found
            while (freq[nums[right]] > 1)
            {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            // If the current window size is exactly k, consider it for max_sum
            if (right - left + 1 == k)
            {
                max_sum = max(max_sum, sum);
                // Remove the leftmost element to slide the window
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }
        }

        return max_sum;
    }
};
