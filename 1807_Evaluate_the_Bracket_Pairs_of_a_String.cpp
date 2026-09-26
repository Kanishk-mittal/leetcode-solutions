#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string getReplacement(unordered_map<string,string>&mp,string s){
    if (mp.find(s)!=mp.end())
    {
        return mp[s];
    }
    return "?";
}

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(vector<string>& i:knowledge){
            mp[i[0]]=i[1];
        }
        int n = s.size();
        string result ="";
        for (int i = 0; i < n; i++)
        {
            if (s[i]=='(')
            {
                int j = i+1;
                while (s[j]!=')')
                {
                    j++;
                }
                // now we have to replace seciton i to j
                result+=getReplacement(mp,s.substr(i+1,j-i-1));
                i=j;
            }else{
                result.push_back(s[i]);
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

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge={{"name","bob"},{"age","two"}};
    cout<<sol.evaluate(s,knowledge)<<endl;
    return 0;
}
