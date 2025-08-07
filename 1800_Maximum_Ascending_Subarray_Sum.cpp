# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        // using sliding window approacn return the maximum sum of a strictly increasing subarray
        int n = nums.size();
        int sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
            }
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}