#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        int curr=0;
        for(char c : s){
            if (c=='(')
            {
                curr++;
            }
            if (c==')')
            {
                curr--;
            }
            result=max(result,curr);
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