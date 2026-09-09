#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int distinctSubseqII(string s) {
        int MOD=1e9+7;
        int n = s.size();
        vector<long long>dp(n+1,1);
        unordered_map<char,int>mp;
        for (int i = 0; i < n; i++)
        {
            dp[i+1]=dp[i]*2;
            if (mp.find(s[i])!=mp.end())
            {
                dp[i+1]-=dp[mp[s[i]]];
            }
            mp[s[i]]=i;
            dp[i+1]%=MOD;
        }
        return (dp[n]-1)%MOD;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();