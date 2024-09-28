#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0]; // Initialize candidate
        int count = 1;           // Initialize count for the candidate

        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0)
            {
                candidate = nums[i]; // Update the candidate if count reaches 0
                count = 1;
            }
            else if (candidate == nums[i])
            {
                count++; // Increment count if the current element is the same as the candidate
            }
            else
            {
                count--; // Decrement count if the current element is different from the candidate
            }
        }

        return candidate;
    }
};