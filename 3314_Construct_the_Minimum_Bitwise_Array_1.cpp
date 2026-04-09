#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int lastUnset(int n)
    {
        int count = 0;
        while (n & 1)
        {
            n = n >> 1;
            count++;
        }
        return count;
    }

public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> result;
        result.reserve(nums.size());
        for (int x : nums)
        {
            if (x == 2)
            {
                result.push_back(-1);
            }
            else
            {
                int temp = lastUnset(x);
                int map = 1 << (temp - 1);
                result.push_back(x ^ map);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 5, 7};
    vector<int> result = sol.minBitwiseArray(nums);

    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}