# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private: 
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};