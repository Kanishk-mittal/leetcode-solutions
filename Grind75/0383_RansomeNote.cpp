#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> freq(26, 0);
        for (char c : magazine)
        {
            freq[c - 'a']++;
        }
        for (char c : ransomNote)
        {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0)
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
    return 0;
}