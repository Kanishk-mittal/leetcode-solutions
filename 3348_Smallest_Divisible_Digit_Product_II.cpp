#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * Check if provided t value result in a valid answer
     *
     * @param t provided t value
     * @return boolean value whether t contains only 2,3,5,7 as prime factors
     */
    bool check(long long t)
    {
        for (int i : {2, 3, 5, 7})
        {
            while (t % i == 0)
            {
                t /= i;
            }
        }
        return t == 1;
    }

    /**
     * Generates suffix which fullfull the product requirement and size
     *
     * @param req the product required from remaining digits
     * @param size allowd size
     * @return return suffix
     */
    string build_end(long long req, int size)
    {
        // filling from least significant bit
        string res = "";
        for (int i = 10 - 1; i >= 2; i--)
        {
            while (req % i == 0)
            {
                req /= i;
                res.push_back('0' + i);
            }
        }
        // filling remaining digits
        if (res.size() < size)
        {
            int temp = res.size();
            for (int i = 0; i < size - temp; i++)
            {
                res.push_back('1');
            }
        }
        // reverse and create final string
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string smallestNumber(string num, long long t)
    {
        if (!check(t))
        {
            return "-1";
        }
        int n = num.size();
        vector<long long> rem(n + 1, 0);
        rem[0] = t;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == '0')
            {
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], (long long)(num[i] - '0'));
        }

        size_t z = num.find('0');

        // Fixed: Ensure the whole string is checked and it has no zeros
        if (z == string::npos && rem[n] == 1)
        {
            return num;
        }

        int start = (z != string::npos) ? static_cast<int>(z) : n - 1;

        for (int i = start; i >= 0; i--)
        {
            int end_size = n - i - 1;
            for (int d = ((int)(num[i] - '0')) + 1; d < 10; d++)
            {
                // Find the required product for the rest of the digits
                long long current_req = rem[i] / gcd(rem[i], (long long)d);
                string last = build_end(current_req, end_size);

                // If it fits within the allowed size, construct and return the string
                if (last.size() == end_size)
                {
                    return num.substr(0, i) + to_string(d) + last;
                }
            }
        }

        // If we can't find a valid number of the same length,
        // we add an extra digit to the length and pad with '1's.
        return build_end(t, n + 1);
    }
};

int main()
{
    Solution sol;
    // Example test case:
    // cout << sol.smallestNumber("1234", 256) << "\n";
    return 0;
}