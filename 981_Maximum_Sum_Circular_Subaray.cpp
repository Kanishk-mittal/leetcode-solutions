# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {

        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = nums[0], minSum = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {

            // Kadane's to find maximum sum subnumsay
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);

            // Kadane's to find minimum sum subnumsay
            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);

            // Sum of all the elements of input numsay
            totalSum = totalSum + nums[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        // If the minimum subnumsay is equal to total Sum
        // then we just need to return normalSum
        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};