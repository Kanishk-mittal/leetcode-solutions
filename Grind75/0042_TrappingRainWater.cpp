#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n < 3)
        {
            return 0;
        }
        int left = height[0];
        vector<int> right(n, 0);
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i], right[i + 1]);
        }
        int result = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int temp = min(left, right[i + 1]) - height[i];
            result += max(temp, 0);
            left = max(left, height[i]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> h = {4, 2, 0, 3, 2, 5};
    cout << sol.trap(h) << endl;
    return 0;
}