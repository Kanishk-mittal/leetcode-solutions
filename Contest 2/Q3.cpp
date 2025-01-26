#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int get_max_freq(vector<int> &freq)
    {
        int max_freq = 0;
        for (int i = 0; i < freq.size(); i++)
        {
            max_freq = max(max_freq, freq[i]);
        }
        return max_freq;
    }

public:
    int maxFrequency(vector<int> &nums, int k)
    {
        vector<int> freq(51, 0);
        int left = 0, right = 0;
        int left_k_freq = 0, right_k_freq = 0, max_value = 0;

        // Step 1: Count all occurrences of `k` in the array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
            {
                right_k_freq++;
            }
        }

        // Step 2: Sliding window approach
        while (right < nums.size())
        {
            // Expand the window by including nums[right]
            freq[nums[right]]++;
            if (nums[right] == k)
            {
                right_k_freq--;
            }

            // Calculate the current value to maximize
            int value_to_maximise = left_k_freq + right_k_freq + get_max_freq(freq);

            // Update the maximum value found
            max_value = max(max_value, value_to_maximise);

            // Shrink the window if it becomes invalid
            while (left <= right && value_to_maximise <= max_value)
            {
                freq[nums[left]]--;
                if (nums[left] == k)
                {
                    left_k_freq++;
                }
                left++;
                value_to_maximise = left_k_freq + right_k_freq + get_max_freq(freq);
            }
            // Increment the right pointer to expand the window
            right++;
        }

        return max_value;
    }
};

