#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> temp(nums.size() - 1);
        while (temp.size() > 1)
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                temp[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = temp;
            temp.clear();
            temp.resize(nums.size() - 1);
        }
        return (nums[0] + nums[1]) % 10;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "Triangular Sum: " << sol.triangularSum(nums) << std::endl;
    return 0;
}
