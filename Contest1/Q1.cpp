# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> prefixSum(size + 1, 0);
        int totalSum = 0;
        for (int i = 0; i < size; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int i = 0; i < size; i++)
        {
            int start=max(0,i-nums[i]);
            int end=i;
            int sum=prefixSum[end+1]-prefixSum[start];
            totalSum+=sum;
        }
        return totalSum;
    }
};

    int
    main(int argc, char const *argv[])
{
    
    return 0;
}