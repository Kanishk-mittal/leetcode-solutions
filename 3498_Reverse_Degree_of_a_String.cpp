#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total=0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            total+=(16-(s[i]-'a'))*(i+1);
        }
        return total;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();