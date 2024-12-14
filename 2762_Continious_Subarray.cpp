# include <iostream>
# include <vector>
# include <deque>

using namespace std;

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        long long count = 0;
        deque<int> minDeque, maxDeque;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            // Update the minDeque
            while (!minDeque.empty() && nums[minDeque.back()] > nums[right])
                minDeque.pop_back();
            minDeque.push_back(right);

            // Update the maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            // Check the condition: max - min <= 2
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2)
            {
                // Move the left pointer to shrink the window
                if (minDeque.front() == left)
                    minDeque.pop_front();
                if (maxDeque.front() == left)
                    maxDeque.pop_front();
                left++;
            }

            // Count subarrays ending at 'right'
            count += right - left + 1;
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 4, 2, 4};
    Solution obj;
    cout << obj.continuousSubarrays(nums) << endl;
    return 0;
}