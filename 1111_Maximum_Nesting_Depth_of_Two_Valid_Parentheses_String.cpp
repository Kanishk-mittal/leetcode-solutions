#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0;
        vector<int> result;
        for(char c: seq){
            if (c=='(')
            {
                result.push_back(d%2);
                d++;
            }else{
                d--;
                result.push_back(d%2);
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