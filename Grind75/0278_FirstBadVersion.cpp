#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    return version >= 7;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1;
        int r = n;
        int result = n;
        while (l < r)
        {
            int mid = l + ((r - l) / 2);
            if (isBadVersion(mid))
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
    cout << sol.firstBadVersion(200);
    return 0;
}