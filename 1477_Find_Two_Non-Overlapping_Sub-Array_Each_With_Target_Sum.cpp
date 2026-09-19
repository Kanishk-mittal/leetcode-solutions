#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // Map prefix sums to their 1-based indices
        unordered_map<int, int> mp;
        vector<int> prefix(n + 1, 0);
        mp[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
            mp[prefix[i + 1]] = i + 1;
        }

        // forward[i] = min length of valid subarray ending at or before index i
        vector<int> forward(n, -1);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                forward[i] = forward[i - 1];
            }
            // Search for start index j such that prefix[i+1] - prefix[j] == target
            int neededPrefix = prefix[i + 1] - target;
            if (mp.find(neededPrefix) != mp.end()) {
                int currLength = (i + 1) - mp[neededPrefix];
                if (forward[i] == -1) {
                    forward[i] = currLength;
                } else {
                    forward[i] = min(forward[i], currLength);
                }
            }
        }

        // backward[i] = min length of valid subarray starting at or after index i
        vector<int> backward(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                backward[i] = backward[i + 1];
            }
            // Search for end index j such that prefix[j] - prefix[i] == target
            int neededPrefix = target + prefix[i];
            if (mp.find(neededPrefix) != mp.end()) {
                int currLength = mp[neededPrefix] - i;
                if (backward[i] == -1) {
                    backward[i] = currLength;
                } else {
                    backward[i] = min(backward[i], currLength);
                }
            }
        }

        // Combine non-overlapping ranges split at boundary between i and i+1
        int ans = -1;
        for (int i = 0; i < n - 1; i++) {
            if (forward[i] != -1 && backward[i + 1] != -1) {
                int sum = forward[i] + backward[i + 1];
                if (ans == -1 || sum < ans) {
                    ans = sum;
                }
            }
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