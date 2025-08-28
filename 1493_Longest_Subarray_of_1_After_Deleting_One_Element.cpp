#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    bool isAllOne(vector<int>& nums) {
        for (int num : nums) {
            if (num != 1) return false;
        }
        return true;
    }
public:
    int longestSubarray(vector<int>& nums) {
        if(isAllOne(nums)) {
            return nums.size() - 1; // If all are 1s, we must delete one element
        }
        int l=0;
        int zero_count=0;
        // adding 2 zero at the end to make sliding window easier
        int max_window=0;
        int r;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0){
                zero_count++;
            }
            while(zero_count>1 && l<r){
                if(nums[l]==0){
                    zero_count--;
                }
                l++;
            }
            max_window=max(max_window,(r-l+1)-zero_count);
        }
        return max_window;
    }
};

int main() {
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    Solution sol;
    cout << sol.longestSubarray(nums) << endl;
    return 0;
}