#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        // take the first half and sort it
        // using count sort as we only have 26 characters
        vector<int> count(26, 0);
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            count[s[i] - 'a']++;
        }
        int curr = 0;
        for (int i = 0; i < n / 2; i++)
        {
            while (count[curr] == 0)
            {
                curr++;
            }
            s[i] = 'a' + curr;
            s[(n - 1) - i] = 'a' + curr;
            count[curr]--;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    cout << sol.smallestPalindrome("baab") << endl;
    return 0;
}