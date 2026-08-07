#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int product(int n)
    {
        int result = 1;
        while (n > 0)
        {
            result *= n % 10;
            n /= 10;
        }
        return result;
    }

public:
    int smallestNumber(int n, int t)
    {
        while (product(n) % t != 0)
        {
            n++;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    return 0;
}