#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); // number of rows
        int m = t.size(); // number of columns 
        vector<vector<int>>count(n+1,vector<int>(m+1,0));
        /**
         * row number = position in s
         * column number = position in t
         * so last row will be a all 0 as we have exhausted all provided characcters set while initializing
         * last column will be all 1 as we have achived all character for targer
         */
        for (int i = 0; i < n+1; i++)
        {
            count[i][m]=1;
        }
        /**
         *  for the remaining we will follow the simple rule 
         *  if(s[i]==t[j]){
         *      count[i][j]=count[i+1][j]  // leaving the current character
         *                  +count[i+1][j+1] // taking the current character
         *  }else{
         *      count [i][j]=count[i+1][j] // there is no other option except leaving this character
         *  }
         */
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i]==t[j])
                {
                    count[i][j]=count[i+1][j]+count[i+1][j+1];
                }else{
                    count[i][j]=count[i+1][j];
                }
            }
        }
        return count[0][0];
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();