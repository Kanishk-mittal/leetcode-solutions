#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long current_cost = 0;
        
        // Monotonic decreasing deque storing indices of elements.
        // dq.front() is always the index of the maximum element in [l, r].
        deque<int> dq; 
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            // 1. Expand window to the left by adding nums[l].
            // All elements in the deque smaller than nums[l] must be raised to nums[l].
            while (!dq.empty() && nums[dq.back()] < nums[l]) {
                int idx = dq.back();
                dq.pop_back();
                
                // Determine how many elements were governed by nums[idx]
                int next_idx = dq.empty() ? r + 1 : dq.back();
                long long count = next_idx - idx;
                
                // Add the extra operations needed to raise those elements from nums[idx] to nums[l]
                current_cost += count * (nums[l] - nums[idx]);
            }
            dq.push_back(l);
            
            // 2. Shrink window from the right if total operations exceed k
            while (current_cost > k) {
                // nums[dq.front()] is the max value in [l, r], which nums[r] had to match
                current_cost -= (nums[dq.front()] - nums[r]);
                
                if (dq.front() == r) {
                    dq.pop_front();
                }
                --r;
            }
            
            // 3. Every subarray starting at l and ending anywhere from l to r is valid
            ans += (r - l + 1);
        }
        
        return ans;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();