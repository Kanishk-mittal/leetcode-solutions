#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to find the min and max in the range [l, r)
    pair<int, int> getMinMax(const vector<int>& nums, int l, int r) {
        int min_val = nums[l];
        int max_val = nums[l];
        for (int i = l + 1; i < r; i++) {
            if (nums[i] < min_val) min_val = nums[i];
            if (nums[i] > max_val) max_val = nums[i];
        }
        return {min_val, max_val};
    }

    bool isSortable(const vector<int>& nums, int l, int r){
        int dropCount = 0;
        for (int i = l; i < r - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                dropCount++;
            }
        }
        if (dropCount == 0) {
            return true;
        } else if (dropCount == 1) {
            // FIXED: Using r-1 for the last element and l for the first element
            return nums[r - 1] <= nums[l];
        } else {
            return false;
        }
    }
    
public:
    int sortableIntegers(const vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        
        // Loop updated to include i <= n, so the whole array as one group is checked
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                bool sortable = true;
                int prev_max = -1; // Assuming array contains non-negative numbers
                
                for (int j = 0; j < n; j += i) {
                    // 1. Check if the chunk itself is sortable
                    if (!isSortable(nums, j, j + i)) {
                        sortable = false;
                        break;
                    }
                    
                    // 2. Get min and max of the current chunk
                    pair<int, int> minMax = getMinMax(nums, j, j + i);
                    
                    // 3. Ensure previous group's max is <= current group's min
                    if (j > 0 && prev_max > minMax.first) {
                        sortable = false;
                        break;
                    }
                    
                    // Update prev_max for the next group comparison
                    prev_max = minMax.second;
                }
                
                if (sortable) {
                    result += i;
                }
            }
        }
        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(int argc, char const *argv[]) {
    vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Size of array: " << arr.size() << endl;
    Solution sol;
    cout << sol.sortableIntegers(arr) << endl;
    return 0;
}