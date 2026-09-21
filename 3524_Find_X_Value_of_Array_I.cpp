#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
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
        vector<long long> result(k,0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                result[j]+=subarrayCount[i][j];
            }
        }
        return result;
    }
};

/**
 * What we have to do
 * we have to return an array fo size k where 
 * result [i] = count to subarray such that product of subarray%K == i
 */

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    Solution sol;
    vector<long long> result = sol.resultArray(nums,3);
    return 0;
}
