#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        /**
         * subarrayCount[i][j] will store number of subarray in range [i ... n-1] where product%k == j
         */
        vector<vector<long long>> subarrayCount(n, vector<long long>(k,0));
        // the last column
        subarrayCount[n-1][nums[n-1]%k]=1;
        // will fill it backwards
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < k; j++)
            {
                int mod=nums[i]%k;
                subarrayCount[i][(j*mod)%k]+=subarrayCount[i+1][j];
            }
            subarrayCount[i][nums[i]%k]++;
        }
        // when we update an index i we need to update the dp table from [i ... 0]
        
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();