#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSubstring(string pattern, string word)
    {
        return word.find(pattern) != string::npos;
    }

public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int result = 0;
        for (string p : patterns)
        {
            if (isSubstring(p, word))
            {
                result++;
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