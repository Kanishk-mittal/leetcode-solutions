#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // calculating right smallest
        int n = heights.size();
        stack<int> s;
        vector<int> right(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        // actual solution calculation
        s = stack<int>();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            int l = s.empty() ? -1 : s.top();
            result = max(result, heights[i] * (right[i] - l - 1));
            s.push(i);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(arr);
    return 0;
}