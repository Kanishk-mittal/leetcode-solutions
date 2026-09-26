#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l =0;
        int r = nums.size()-1;
        while (l<r)
        {
            int mid = l+((r-l)/2);
            if (nums[mid]==nums[mid^1])
            {
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return nums[l];
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<sol.singleNonDuplicate(nums);
    return 0;
}
