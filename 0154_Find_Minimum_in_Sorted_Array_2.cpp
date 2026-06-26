#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + ((r - l) / 2);
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if (nums[mid] == nums[r])
            {
                r--;
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5};
    cout << sol.findMin(nums) << endl;
    return 0;
}