#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> arr(mx + 1, 0);

        // 1. Find frequency of all numbers
        for (int i : nums)
        {
            arr[i]++;
        }

        // 2. Count number of elements divisible by i
        // FIX: Start at i = 1 to prevent infinite loops (j += 0)
        for (int i = 1; i <= mx; i++)
        {
            for (int j = i * 2; j <= mx; j += i)
            {
                arr[i] += arr[j];
            }
        }

        // 3. Pairs where both numbers are divisible by i
        // FIX: Start at i = 1
        for (int i = 1; i <= mx; i++)
        {
            arr[i] = (arr[i] * (arr[i] - 1)) / 2;
        }

        // 4. Pairs with an EXACT gcd of i
        // FIX: Iterate backward from mx down to 1 so you don't double-subtract
        for (int i = mx; i >= 1; i--)
        {
            for (int j = i * 2; j <= mx; j += i)
            {
                arr[i] -= arr[j];
            }
        }

        // 5. Generate prefix sums
        // FIX: Start from 1. arr[0] naturally stays 0.
        for (int i = 1; i < mx; i++)
        {
            arr[i + 1] = arr[i] + arr[i + 1];
        }

        // 6. Answer the queries using binary search
        int q = queries.size();
        vector<int> answer(q);
        for (int i = 0; i < q; i++)
        {
            // FIX 1: Flipped subtraction to (iterator - arr.begin())
            // FIX 2: Used upper_bound because queries are 0-indexed
            answer[i] = upper_bound(arr.begin(), arr.end(), queries[i]) - arr.begin();
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 4};
    vector<long long> queries = {0, 2, 2};
    vector<int> result = sol.gcdValues(nums, queries);
    for (int r : result)
    {
        cout << r << endl;
    }
    return 0;
}