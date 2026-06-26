#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> countS(26, 0);
        for (char c : s)
        {
            countS[c - 'a']++;
        }
        vector<int> countT(26, 0);
        for (char c : t)
        {
            countT[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (countS[i] != countT[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isAnagram("abc", "bca");
    return 0;
}