#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long result = 0;
        long long sum = 0;
        int i = 0;
        while (n > 0)
        {
            int digit = n % 10;
            n /= 10;
            if (digit != 0)
            {
                result = result + (digit * pow(10, i));
                i++;
                sum += digit;
            }
        }
        return result * sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.sumAndMultiply(10203004);
    return 0;
}