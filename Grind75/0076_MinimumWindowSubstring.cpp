#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &tfreq, vector<int> &sfreq)
    {
        for (int i = 0; i < 52; i++)
        {
            if (tfreq[i] > sfreq[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        vector<int> tfreq(52, 0);
        vector<int> sfreq(52, 0);
        for (char c : t)
        {
            if (c >= 'a' && c <= 'z')
            {
                tfreq[c - 'a']++;
            }
            else
            {
                tfreq[(c - 'A') + 26]++;
            }
        }
        int l = 0;
        int bestLen = INT_MAX;
    }
};

int main()
{
    Solution sol;
    return 0;
}