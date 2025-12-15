#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long result = 0;
        int l = 0, r = 0;
        int n = prices.size();

        while (r < n)
        {
            while (r < n && (l == r || (prices[r - 1] - prices[r]) == 1))
            {
                r++;
            }
            long long size = r - l;
            result += size * (size + 1) / 2;
            l = r;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {3, 2, 1, 4};
    cout << sol.getDescentPeriods(prices) << endl; // Output: 7
    return 0;
}