#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++)
        {
            set<int> curr;
            for (int j = 0; j < k; j++)
            {
                curr.insert(nums[i + j]);
            }
            for (int i : curr)
            {
                freq[i]++;
            }
        }
        int result = -1;
        for (pair<int, int> i : freq)
        {
            if (i.second == 1)
            {
                result = max(result, i.first);
            }
        }
        return result;
    }
};

/**
 * Important Observation
 * it can only be either the first or last element because all other will be part of atleast 2 subarray
 * for first and last element check if there is any duplicate in range [0,k-1] and [n-k,n-1]
 * return the largest
 *
 * if k == 1 then we just have to find unique element
 */

int main()
{
    Solution sol;
    return 0;
}