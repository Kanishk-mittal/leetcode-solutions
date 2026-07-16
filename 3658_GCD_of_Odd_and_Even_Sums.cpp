#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        int sumOdd = 0;
        int sumEven = 0;
        int even = 2;
        int odd = 1;
        for (int i = 0; i < n; i++)
        {
            sumEven += even;
            sumOdd += odd;
            even += 2;
            odd += 2;
        }
        return gcd(sumOdd, sumEven);
    }
};

int main()
{
    Solution sol;
    return 0;
}