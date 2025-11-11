#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int fullWeek = n / 7;
        int fullWeekSum = ((fullWeek) * (56 + ((fullWeek - 1) * 7))) / 2;
        int remainingDays = n % 7;
        int remainingDaysSum = ((remainingDays) * ((2 * fullWeek) + remainingDays + 1)) / 2;
        return fullWeekSum + remainingDaysSum;
    }
};

int main()
{
    Solution sol;
    int n = 10; // Example input
    cout << "Total money after " << n << " days: " << sol.totalMoney(n) << endl;
    return 0;
}