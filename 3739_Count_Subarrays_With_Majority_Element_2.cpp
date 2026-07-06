#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, std::less<long long>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution
{
public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : 0);
        }
        ordered_set s;
        for (int i = 0; i < n; i++)
        {
            s.insert(prefix[i] - (i + 1) / 2);
            long long target = prefix[i] - (i / 2);
            long long smaller_elements = s.order_of_key(target);
            long long total_elements = s.size();
            int greater_elements = total_elements - smaller_elements;
            if (s.find(target) != s.end())
            {
                greater_elements--;
            }
            result += greater_elements;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}