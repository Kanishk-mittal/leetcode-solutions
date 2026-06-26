#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 0;
        for (int n : nums)
        {
            if (0 == count)
            {
                candidate = n;
            }
            else if (n == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};

int main()
{
    Solution sol;
    return 0;
}