#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        // first remove all consecutive  and replace them with a single zero
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                temp += '1';
            }
            else
            {
                temp += '0';
                while (s[i] == '0')
                {
                    i++;
                }
                i--;
            }
        }
        // now for each zero count how many one are on its left
        int result = 0;
        int oneCount = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '1')
            {
                oneCount++;
            }
            else
            {
                result += oneCount;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "1001101";
    cout << sol.maxOperations(s) << endl; // Output the result
    return 0;
}