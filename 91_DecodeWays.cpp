#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<string> st = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};

// class Solution
// {
// private:
//     int help(string s, int i, int n)
//     {
//         if (i == n)
//         {
//             // we are at last character
//             return st.count(s.substr(i, 1)); // we will check if that character is in the given string
//         }
//         if (i == n - 1)
//         {
//             // // we have two character remaining
//             // return st.count(s.substr(i, 2)) + help(s, i + 1, n);
//             int r1 = st.count(s.substr(i, 2));
//             int r2 = st.count(s.substr(i, 1)) ? help(s, i + 1, n) : 0;
//             return r1 + r2;
//         }
//         // else we have atleast 3 characters in our input
//         int count = 0;
//         if (st.count(s.substr(i, 1)))
//         {
//             count += help(s, i + 1, n);
//         }
//         if (st.count(s.substr(i, 2)))
//         {
//             count += help(s, i + 2, n);
//         }
//         return count;
//     }

// public:
//     int numDecodings(string s)
//     {
//         int result = help(s, 0, s.size() - 1);
//         return result;
//     }
// };

set<string> st = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 1)
        {
            return st.count(s);
        }
        vector<int> dp(n, 0);
        dp[n - 1] = st.count(s.substr(n - 1, 1));
        dp[n - 2] = st.count(s.substr(n - 2, 2));
        for (int i = n - 2; i >= 0; i--)
        {
            int r1 = 0;
            int r2 = 0;
            if (st.count(s.substr(i, 1)))
            {
                r1 = dp[i + 1];
            }
            if (i + 2 < n && st.count(s.substr(i, 2)))
            {
                r2 = dp[i + 2];
            }
            dp[i] += (r1 + r2);
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    cout << sol.numDecodings("226");
    return 0;
}