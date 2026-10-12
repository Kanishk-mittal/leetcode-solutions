#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int balance =0;
        int n = s.size();
        int result =0;
        for (int i = 0; i < n; i++)
        {
            if (s[i]=='(')
            {
                balance++;
            }else if(s[i]==')'){
                if (!(i+1<n && s[i+1]==')'))
                {
                    result++;
                }else{
                    i++;
                }
                balance--;
            }
            if (balance<0)
            {
                result-=balance;
                balance=0;
            }
        }
        return result+ (balance*2);
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();