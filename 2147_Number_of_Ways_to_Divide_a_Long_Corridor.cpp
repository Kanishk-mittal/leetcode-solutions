#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfWays(string corridor)
    {
        long long result = 1;
        int MOD = 1000000000 + 7;
        int totalSeats = 0;
        for (char c : corridor)
        {
            if (c == 'S')
            {
                totalSeats++;
            }
        }
        if (totalSeats % 2 != 0 || totalSeats == 0)
        {
            return 0;
        }
        int currentSeats = 0;
        int plantsBetweenSegments = 0;
        for (char c : corridor)
        {
            if (c == 'S')
            {
                currentSeats++;
            }
            if (currentSeats == 3)
            {
                result = (result * (plantsBetweenSegments + 1)) % MOD;
                currentSeats = 1;
                plantsBetweenSegments = 0;
            }
            else if (currentSeats == 2 && c == 'P')
            {
                plantsBetweenSegments++;
            }
        }
        return (int)result;
    }
};
int main()
{
    Solution sol;
    string corridor = "PPSPPSSSSSSSPSPS";
    cout << sol.numberOfWays(corridor) << endl;
    return 0;
}