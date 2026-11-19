#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m,string(n,'#'));
        for (int i = 0; i < m; i++)
        {
            result[i][0]='.';
        }
        result[m-1]=string(n,'.');
        return result;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();