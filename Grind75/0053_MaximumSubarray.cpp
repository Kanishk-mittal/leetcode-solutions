#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int sum = 0;
        int m = 0;
        for (int n : nums)
        {
            sum += n;
            result = max(result, sum - m);
            m = min(m, sum);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}