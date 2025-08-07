# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int get_peak(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return left;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1])
            return get_peak(nums, left, mid);
        return get_peak(nums, mid + 1, right);
    }
public:
    int findPeakElement(vector<int> &nums)
    {
        return get_peak(nums, 0, nums.size() - 1);
    }
};