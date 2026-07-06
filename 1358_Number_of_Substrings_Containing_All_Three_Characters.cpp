#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int result = 0;
        vector<int> freq(3, 0);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while ((freq[0] < 1 || freq[1] < 1 || freq[2] < 1) && j < n)
            {
                freq[s[j] - 'a']++;
                j++;
            }
            if (freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1)
            {
                result += n - j + 1;
            }
            freq[s[i] - 'a']--;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.numberOfSubstrings("abcabc") << endl;
    return 0;
}

/*
for each starting index i we will find what is the minimum ending to get all three characters then we can add n-j to the answer where n is the length of the string and j is the minimum ending index.
*/