# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int rob_support(vector<int> &nums, int start, vector<int> &memo)
    {
        if (start >= nums.size())
            return 0;
        if (memo[start] != -1)
            return memo[start];
        int result = max(rob_support(nums, start+1, memo), nums[start] + rob_support(nums, start+2, memo));
        memo[start] = result;
        return result;
    }
public:
    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return rob_support(nums, 0, memo);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}