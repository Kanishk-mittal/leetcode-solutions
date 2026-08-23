#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    // Helper function for LCM
    long long getLCM(long long a, long long b)
    {
        return (a / gcd(a, b)) * b; // Avoid overflow by dividing first
    }

    /**
     * Finds how many numbers <= k are divisible by at least one coin
     */
    long long countDivisible(long long k, vector<int> &coins)
    {
        int n = coins.size();
        long long count = 0;

        // Iterate through all 2^n - 1 non-empty subsets
        for (int mask = 1; mask < (1 << n); ++mask)
        {
            long long currentLCM = 1;
            int setBits = 0;

            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    setBits++;
                    currentLCM = getLCM(currentLCM, coins[i]);
                    // If LCM exceeds k, k / currentLCM becomes 0
                    if (currentLCM > k)
                        break;
                }
            }

            // Include (add) if odd number of coins, Exclude (subtract) if even
            if (setBits % 2 == 1)
            {
                count += (k / currentLCM);
            }
            else
            {
                count -= (k / currentLCM);
            }
        }

        return count;
    }

public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        long long l = 1;
        // Upper bound: Smallest coin repeated k times
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long r = minCoin * k;
        long long ans = r;

        // Binary Search on Answer
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;

            if (countDivisible(mid, coins) >= k)
            {
                ans = mid;
                r = mid - 1; // Try finding a smaller valid number
            }
            else
            {
                l = mid + 1; // Need more multiples
            }
        }

        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();