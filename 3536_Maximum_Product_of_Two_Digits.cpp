#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        // lets simply try to find the max two digits
        int m1 = -1;
        int m2 = -1;
        while (n > 0)
        {
            int digit = n % 10;
            if (digit > m1)
            {
                m2 = m1;
                m1 = digit;
            }
            else if (digit > m2)
            {
                m2 = digit;
            }
            n /= 10;
        }
        return max(0, m1 * m2);
    }
};

int main()
{
    Solution sol;
    cout << sol.maxProduct(10) << endl;
    return 0;
}