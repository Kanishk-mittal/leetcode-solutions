#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        // we have to find maximu possible sum of two continious block of zeroes
        s.push_back('1');
        vector<int> block;
        int n = s.size();
        int lastPos = -1;
        int oneCount = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                oneCount++;
                if (i - lastPos > 1)
                {
                    block.push_back(i - lastPos - 1);
                }
                lastPos = i;
            }
        }
        int maxSum = -1;
        for (int i = 1; i < block.size(); i++)
        {
            maxSum = max(maxSum, block[i] + block[i - 1]);
        }
        if (maxSum > 0)
        {
            oneCount += maxSum;
        }
        return oneCount;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxActiveSectionsAfterTrade("1000100") << endl;
    return 0;
}