#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;
        for(char c : s){
            if (c=='(')
            {
                balance++;
                if (balance>1)
                {
                    result.push_back(c);
                }
            }else{
                balance--;
                if (balance)
                {
                    result.push_back(c);
                }
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