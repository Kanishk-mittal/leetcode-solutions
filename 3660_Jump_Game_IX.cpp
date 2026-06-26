#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int n = nums.size();
        stack<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            vector<int> np = {nums[i], i, i};
            while ((!s.empty()) && (s.top()[0] > nums[i]))
            {
                np[0] = max(s.top()[0], np[0]);
                np[1] = min(np[1], s.top()[1]);
                np[2] = max(np[2], s.top()[2]);
                s.pop();
            }
            s.push(np);
        }
        vector<int> result(n);
        while (!s.empty())
        {
            for (int i = s.top()[1]; i <= s.top()[2]; i++)
            {
                result[i] = s.top()[0];
            }
            s.pop();
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 3};
    vector<int> result = sol.maxValue(nums);
    for (int n : result)
    {
        cout << n << " ";
    }
    return 0;
}