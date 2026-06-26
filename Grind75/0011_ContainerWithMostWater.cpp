#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int result = 0;
        while (l < r)
        {
            int area = min(height[l], height[r]) * (r - l);
            result = max(result, area);
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
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