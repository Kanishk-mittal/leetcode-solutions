#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // we will have two array storing the length of 
        int mxe = nums[n-1];
        vector<int> dp(mxe+2);
        for (int i : nums){
            dp[i+1]=max(dp[i+1],dp[i]+1);
            dp[i]=max(dp[i],dp[i-1]+1);
        }
        return *max_element(dp.begin(),dp.end());
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();