#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int r = 0;
        int result = 0;
        int n = s.size();
        vector<int> freq(26, 0);
        for (int l = 0; l < n; l++)
        {
            while (r < n && freq[s[r] - 'a'] < 2)
            {
                freq[s[r] - 'a']++;
                r++;
            }
            result = max(result, r - l);
            freq[s[l] - 'a']--;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}