# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int possbileWays(vector<int> &nums, int target, int index)
    {
        if (index == nums.size())
        {
            if (target == 0)
                return 1;
            return 0;
        }
        return possbileWays(nums, target - nums[index], index + 1) + possbileWays(nums, target + nums[index], index + 1);
    }
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return possbileWays(nums, target, 0);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}