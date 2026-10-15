#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum>num*9)
        {
            return "";
        }
        string result="";
        while (sum)
        {
            int val = min(sum,9);
            result.push_back('0'+val);
            sum -=val;
            num--;
        }
        for (int i = 0; i < num; i++)
        {
            result.push_back('0');
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