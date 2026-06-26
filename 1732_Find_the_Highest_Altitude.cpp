#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int current = 0;
        int result = 0;
        for (int i : gain)
        {
            current += i;
            result = max(result, current);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}