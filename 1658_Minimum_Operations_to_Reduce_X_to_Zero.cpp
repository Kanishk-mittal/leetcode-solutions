#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxSubarraySize=-1;
        int n = nums.size();
        int s =0;
        for (int i = 0; i < n; i++)
        {
            s+=nums[i];
        }
        int l=0;
        int target = s-x;
        int current=0;
        for (int r = 0; r < n; r++)
        {
            current+=nums[r];
            while (l<=r && current>target)
            {
                current-=nums[l];
                l++;
            }
            if (current==target)
            {
                maxSubarraySize=max(maxSubarraySize, (r-l)+1);
            }
        }
        if (maxSubarraySize==-1)
        {
            return -1;
        }
        return n-maxSubarraySize;
    }
};

/**
 * let the sum of whole array be s
 * if we calcualte the largest subarray with sum as s-x
 * then we can use the remaining suffix and prefix for our answer
 */

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,20,1,1,3};
    Solution sol;
    cout<<sol.minOperations(nums,10)<<endl;;
    return 0;
}
