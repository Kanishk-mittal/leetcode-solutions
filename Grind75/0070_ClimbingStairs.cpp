#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int fibonacci(int n)
    {
        if (2 > n)
        {
            return n;
        }
        int p1 = 0;
        int p2 = 1;
        for (int i = 0; i < n; i++)
        {
            int temp = p1 + p2;
            p1 = p2;
            p2 = temp;
        }
        return p2;
    }

public:
    int climbStairs(int n)
    {
        return fibonacci(n);
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(4);
    return 0;
}