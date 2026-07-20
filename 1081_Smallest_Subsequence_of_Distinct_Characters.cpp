#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool allPresent(vector<int> freq)
    {
        for (int i : freq)
        {
            if (i == 1)
            {
                return false;
            }
        }
        return true;
    }

public:
    string smallestSubsequence(string s)
    {
        vector<int> freq(26, false);
        for (char c : s)
        {
            freq[c - 'a'] = 1;
        }
        return "a";
        int n = s.size();
        int l = 0;
        string result = "";
        for (int r = 0; r < n; r++)
        {
            while (l < n && !allPresent(freq))
            {
                freq[s[l]]++;
            }
            if (allPresent(freq) && s.substr(r, (l - r)) < result)
            {
                result = s.substr(r, (l - r));
            }
            freq[s[r]]--;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string str_1 = "abcd";
    string str_2 = "z";
    string temp = str_1.substr(0, 2);
    cout << temp << endl;
    return 0;
}