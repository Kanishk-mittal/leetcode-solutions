#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        vector<int> s;
        int res = 0;
        for (int a : nums)
        {
            while (!s.empty() && s.back() > a)
            {
                s.pop_back();
            }
            if (a == 0)
                continue;
            if (s.empty() || s.back() < a)
            {
                ++res;
                s.push_back(a);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    cout << sol.minOperations(nums) << endl; // Output: 3
    return 0;
}