#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 1;
        while (binary_search(nums.begin(), nums.end(), k * i))
        {
            i++;
        }
        return k * i;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();