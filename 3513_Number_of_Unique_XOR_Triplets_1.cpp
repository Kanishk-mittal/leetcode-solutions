#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return 2;
        }
        int maxPos = log2(n);
        return 1 << (maxPos + 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.uniqueXorTriplets(nums) << endl;
    return 0;
}