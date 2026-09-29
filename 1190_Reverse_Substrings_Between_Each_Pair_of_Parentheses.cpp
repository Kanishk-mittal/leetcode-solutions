#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string result="";
        for(char c:s){
            if (c!=')')
            {
                result.push_back(c);
                continue;
            }
            queue<char>q;
            while (result.back()!='(')
            {
                q.push(result.back());
                result.pop_back();
            }
            result.pop_back(); // removing the parenthessis
            while (!q.empty())
            {
                result.push_back(q.front());
                q.pop();
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