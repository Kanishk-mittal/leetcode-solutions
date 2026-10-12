#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>bitCount(32,0);
        for(int i : nums){
            for (int j = 0; j < 32; j++)
            {
                if (i&(1<<j))
                {
                    bitCount[j]++;
                }
            }
        }
        // generating maximum k numbers using these bits as in provided operation we can transfer a bit from one position to another 
        vector<int>topk;
        for (int i = 0; i < k; i++)
        {
            int temp=0;
            for (int j = 32 - 1; j >= 0; j--)
            {
                if (bitCount[j])
                {
                    temp|=(1<<j);
                    bitCount[j]--;
                }
            }
            topk.push_back(temp);
        }
        int MOD = 1e9+7;
        long long result =0;
        for(long long i : topk){
            result+=i*i;
            result%=MOD;
        }
        return result;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();