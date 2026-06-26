#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pFreq(26, 0);
        vector<int> sFreq(26, 0);
        for (char c : p)
        {
            pFreq[c - 'a']++;
        }
        vector<int> result;
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            sFreq[s[right] - 'a']++;
            if (right - left + 1 > p.size())
            {
                sFreq[s[left] - 'a']--;
                left++;
            }
            if (sFreq == pFreq)
            {
                result.push_back(left);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}