#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (char c : word)
        {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            int multiplier = ((i / 8) + 1);
            result += (freq[i] * multiplier);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.minimumPushes("xycdefghij") << endl;
    return 0;
}