#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result=0;
        for(int i = 0 ; i < n ; i++){
            set<int> s;
            for(int j = i ; j < n ; j++){
                s.insert(nums[j]);
                result+=s.size()*s.size();
            }
        }
        return result ;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> arr = {1,2,1};
    cout<<sol.sumCounts(arr)<<endl;
    return 0;
}
