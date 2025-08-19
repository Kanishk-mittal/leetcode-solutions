#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int sumTillN(int n){
        return (n*(n+1))/2;
    }
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int> subarray;
        // our algorithm add when we find a non zero element which will cause problem is last element is zero so lets just add a nonzero element to the end
        nums.push_back(1);
        int l=0;
        for(int r=0;r<nums.size();r++){
            while(l<r && nums[l]!=0){
                l++;
            }
            if(nums[r]!=0 && r-l>0 && nums[l]==0){
                subarray.push_back(r-l);
                l=r;
            }
        }
        int total=0;
        for(int i=0;i<subarray.size();i++){
            total+=sumTillN(subarray[i]);
        }
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 0, 2, 0, 0};
    cout << sol.zeroFilledSubarray(nums) << endl;
    return 0;
}