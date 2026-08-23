#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int digitSum = 0;
        int digitProd = 1;
        int temp = n;
        while (temp > 0)
        {
            int digit = temp % 10;
            temp /= 10;
            digitSum += digit;
            digitProd *= digit;
        }

        return n % (digitProd + digitSum) == 0;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();