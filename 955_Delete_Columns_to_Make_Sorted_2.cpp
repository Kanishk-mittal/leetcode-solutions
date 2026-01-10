#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int check(string str1, string str2, vector<bool> &skip)
    {
        // this will skip the index given by skip and will return the first index where str1>str2
        for (int i = 0; i < str1.size(); i++)
        {
            if (skip[i])
            {
                continue;
            }
            if (str1[1] < str2[i])
            {
                break;
            }
            if (str1[i] > str2[i])
            {
                return i;
            }
        }
        return str1.size() + 2;
    }

public:
    int minDeletionSize(vector<string> &strs)
    {
        int wordLength = strs[0].size();
        int wordCount = strs.size();
        // we will have an array that will store boolean value corespondign to each index whether we need to skip that index or not
        vector<bool> skip(wordLength, false);
        int skipCount = 0;
        int minIndex = wordLength + 2;
        while (true)
        {
            for (int i = 1; i < wordCount - 1; i++)
            {
                minIndex = min(minIndex, check(strs[i - 1], strs[i], skip));
            }
            if (minIndex == wordLength + 2)
            {
                return skipCount;
            }
            else
            {
                skipCount++;
                skip[minIndex] = true;
                minIndex = wordLength + 2;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"abx", "agz", "bgc", "bfc"};
    cout << sol.minDeletionSize(strs);
    return 0;
}