#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return min(
            {
                nums[n-1]-nums[2],
                nums[n-2]-nums[1],
                nums[n-3]-nums[0]
            }
        );
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();