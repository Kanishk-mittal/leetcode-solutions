#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i]=='(')
            {
                st.push(i);
            }else{
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }else{
                    result = max(result, i - st.top());
                }
            }
        }
        return result;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(int argc, char const *argv[])
{
    Solution sol;
    string s="(()";
    cout<<sol.longestValidParentheses(s)<<endl;
    return 0;
}
