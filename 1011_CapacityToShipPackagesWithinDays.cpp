#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &weights, int capacity, int days)
    {
        int count = 0;
        int curr = 0;
        for (int x : weights)
        {
            if (curr + x > capacity)
            {
                count++;
                curr = 0;
            }
            curr += x;
        }
        if (curr > 0)
        {
            count++;
        }
        return count <= days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = INT_MAX;
        int r = 0;
        for (int x : weights)
        {
            l = max(x, l);
            r += x;
        }
        int result = -1;
        while (l < r)
        {
            int mid = l + ((r - l) / 2);
            if (check(weights, mid, days))
            {
                result = mid;
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sol.shipWithinDays(weights, 5);
    return 0;
}