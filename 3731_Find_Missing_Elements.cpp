#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int mi = *min_element(nums.begin(), nums.end());
        vector<bool> freq((mx - mi) + 1, false);
        for (int i : nums)
        {
            freq[i - mi] = true;
        }
        vector<int> result;
        for (int i = 0; i < freq.size(); i++)
        {
            if (!freq[i])
            {
                result.push_back(mi + i);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}