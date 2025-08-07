# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        // calcualte prefix sum
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        // sort the prefix sum
        sort(prefix.begin(), prefix.end());
        return prefix[n] - prefix[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}