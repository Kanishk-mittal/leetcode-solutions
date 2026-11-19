#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        // all pair should be same
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i+=2)
        {
            if (s[i]!=s[i+1])
            {
                result++;
            }
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