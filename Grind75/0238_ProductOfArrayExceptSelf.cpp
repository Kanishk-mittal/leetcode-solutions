#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int prod = 1;
        int zeroCount = 0;
        for (int n : nums)
        {
            if (0 != n)
            {
                prod *= n;
            }
            else
            {
                zeroCount++;
            }
        }
        vector<int> result(n, 0);
        if (zeroCount > 1)
        {
            return result;
        }
        for (int i = 0; i < n; i++)
        {
            if (1 == zeroCount && 0 == nums[i])
            {
                result[i] = prod;
            }
            else if (zeroCount == 0)
            {
                result[i] = prod / nums[i];
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