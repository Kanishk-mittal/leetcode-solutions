#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // find position of 0;
        int zpos = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zpos = i; // Fixed typo: assignment operator instead of equality
                break;
            }
        }
        
        // Helper lambda function to check if the array is sorted in a cyclic manner 
        // with step = 1 (rightward) or step = -1 (leftward)
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zpos + (i - 1) * step + n) % n;
                int curr = (zpos + i * step + n) % n;
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // If it's increasing to the right from 0 (step = 1)
        if (check(1)) {
            ans = min(ans, zpos);          // Rotate directly
            ans = min(ans, n - zpos + 2);  // Reverse, rotate, then reverse back
        }
        
        // If it's increasing to the left from 0 (step = -1)
        if (check(-1)) {
            ans = min(ans, zpos + 2);      // Rotate, then reverse
            ans = min(ans, n - zpos);      // Reverse, then rotate
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();