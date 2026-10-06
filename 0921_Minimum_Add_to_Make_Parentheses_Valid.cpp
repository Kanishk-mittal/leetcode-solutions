#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance=0;
        int result=0;
        for(char c: s){
            if (c=='(')
            {
                balance++;
            }else{
                balance--;  
            }
            if (balance<0)
            {
                result-=balance;
                balance=0;
            }
        }
        return balance+result;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();