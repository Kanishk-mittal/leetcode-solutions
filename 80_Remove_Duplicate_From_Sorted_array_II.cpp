#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = nums.size();
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                if (nums[i] == nums[i - 2])
                {
                    nums.erase(nums.begin() + i);
                    k--;
                    i--;
                }
            }
        }
        // numbers.erase(numbers.begin() + index_to_remove);
        return k;
    }
};