#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.size();
        int s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n / 2; i++)
        {
            if (num[i] == '?')
            {
                c1++;
            }
            else
            {
                s1 += (num[i] - '0');
            }

            if (num[n - i - 1] == '?')
            {
                c2++;
            }
            else
            {
                s2 += (num[n - i - 1] - '0');
            }
        }

        // If total '?' is odd, Alice can always force a mismatch on the final move
        if ((c1 + c2) % 2 != 0)
        {
            return true;
        }

        // Exact game condition: Alice wins if Bob CANNOT force equality
        return (s1 - s2) * 2 != (c2 - c1) * 9;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();