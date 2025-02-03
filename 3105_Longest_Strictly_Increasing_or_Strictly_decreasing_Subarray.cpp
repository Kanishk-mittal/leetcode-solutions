# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int max_increasing = 1, max_decreasing = 1;
        // using sliding window search for maximum strictly increasing subarray
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j < nums.size() - 1 && nums[j] < nums[j + 1])
            {
                j++;
            }
            max_increasing = max(max_increasing, j - i + 1);
            i = j;
        }
        // using sliding window search for maximum strictly decreasing subarray
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j < nums.size() - 1 && nums[j] > nums[j + 1])
            {
                j++;
            }
            max_decreasing = max(max_decreasing, j - i + 1);
            i = j;
        }
        return max(max_increasing, max_decreasing);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}