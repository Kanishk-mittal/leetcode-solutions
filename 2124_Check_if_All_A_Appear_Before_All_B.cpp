#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool bfound=false;
        for(char c:s){
            if(c=='b'){
                bfound=true;
            }
            if(c=='a' && bfound){
                return false;
            }
        }
        return true;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();