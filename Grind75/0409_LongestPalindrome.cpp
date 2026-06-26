#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> freq(52, 0);
        for (char c : s)
        {
            if ('a' <= c && 'z' >= c)
            {
                freq[c - 'a']++;
            }
            else
            {
                freq[26 + (c - 'A')]++;
            }
        }
        // now we will find even sum and max odd and will return it
        int evenSum = 0;
        int hasOdd = 0;
        for (int n : freq)
        {
            if (n & 1)
            {
                // the number is odd
                hasOdd = 1;
                evenSum += (n - 1);
            }
            else
            {
                evenSum += n;
            }
        }
        return evenSum + hasOdd;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("abccCCdd");
    return 0;
}