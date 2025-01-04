# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long totalSum = 0, leftSum = 0;
        int count = 0;

        for (int num : nums)
        {
            totalSum += num;
        }

        for (int i = 0; i < n - 1; ++i)
        {
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum)
            {
            ++count;
            }
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}