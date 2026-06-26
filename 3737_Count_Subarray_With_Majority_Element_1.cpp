#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : 0);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int twoFreq = prefix[j + 1] - prefix[i];
                int len = (j - i) + 1;
                if (twoFreq && twoFreq > (len / 2))
                {
                    result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3};
    cout << sol.countMajoritySubarrays(nums, 2) << endl;
    return 0;
}
