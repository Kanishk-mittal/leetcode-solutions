#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int temp = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            result = max(result, prices[i] - temp);
            temp = min(temp, prices[i]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}