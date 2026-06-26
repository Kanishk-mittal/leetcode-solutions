#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int n = s.size();
        unordered_map<char, int> freq;
        int maxLength = 0;

        while (right < n)
        {
            char currChar = s[right];
            freq[currChar]++;

            while (freq[currChar] > 1)
            {
                char leftChar = s[left];
                freq[leftChar]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;
    return 0;
}