#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            // if mid is the answer
            if (nums[mid] == target)
            {
                return mid;
            }
            // one of the halves will be sorted
            // left half is sorted
            if (nums[l] <= nums[mid])
            {
                // if the requred value exist in left half
                if (nums[l] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            { // in this case the right half is sorted
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    return 0;
}