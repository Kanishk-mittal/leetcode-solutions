#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize runtime to O(log(min(n, m)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (n + m + 1) / 2 - i;

            int maxLeftA  = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightA = (i == n) ? INT_MAX : nums1[i];

            int maxLeftB  = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightB = (j == m) ? INT_MAX : nums2[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Correct partition found
                if ((n + m) % 2 == 1) {
                    return std::max(maxLeftA, maxLeftB);
                } else {
                    return (std::max(maxLeftA, maxLeftB) + std::min(minRightA, minRightB)) / 2.0;
                }
            } else if (maxLeftA > minRightB) {
                high = i - 1; // Move left in A
            } else {
                low = i + 1;  // Move right in A
            }
        }

        return 0.0;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();