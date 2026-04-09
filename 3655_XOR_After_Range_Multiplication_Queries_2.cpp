#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int modInv(int n, int mod = 1000000007)
    {
        long long result = 1;
        long long base = n % mod;
        int exponent = mod - 2;

        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent = exponent / 2;
        }
        return (int)result;
    }

public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int b = sqrt(n);
        int mod = 1000000007;

        // 1. Instantly process all heavy queries (k >= b)
        for (vector<int> &q : queries)
        {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= b)
            {
                for (int i = l; i <= r; i += k)
                {
                    nums[i] = (1ll * nums[i] * v) % mod;
                }
            }
        }

        // 2. Process light queries (k < b) efficiently using O(n) space
        vector<int> diff(n, 1);

        for (int k = 1; k < b; k++)
        {
            // Reset the difference array for the current step size
            fill(diff.begin(), diff.end(), 1);
            bool hasQuery = false;

            // Mark the boundaries for all queries of the current step size
            for (vector<int> &q : queries)
            {
                if (q[2] == k)
                {
                    hasQuery = true;
                    int l = q[0], r = q[1], v = q[3];

                    // Multiply the start of the sequence
                    diff[l] = (1ll * diff[l] * v) % mod;

                    // Divide at the first index out of bounds for this sequence
                    int nextIdx = l + ((r - l) / k + 1) * k;
                    if (nextIdx < n)
                    {
                        diff[nextIdx] = (1ll * diff[nextIdx] * modInv(v)) % mod;
                    }
                }
            }

            if (!hasQuery)
                continue;

            // Cascade the prefix multiplication for step size k
            for (int i = k; i < n; i++)
            {
                diff[i] = (1ll * diff[i] * diff[i - k]) % mod;
            }

            // Immediately apply this step size's multipliers to nums
            for (int i = 0; i < n; i++)
            {
                nums[i] = (1ll * nums[i] * diff[i]) % mod;
            }
        }

        // 3. Compute the final XOR
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result ^= nums[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}