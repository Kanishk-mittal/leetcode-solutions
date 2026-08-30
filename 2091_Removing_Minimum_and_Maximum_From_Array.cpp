#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n<3)
        {
            return n;
        }
        
        int minIndex=min_element(nums.begin(), nums.end())-nums.begin();
        int maxIndex=max_element(nums.begin(), nums.end())-nums.begin();
        int result = INT_MAX;
        // trying to remove from left side 
        result = min(result, max(minIndex, maxIndex)+1);

        // trying to remove both from right side
        result = min(result, max(n-minIndex, n-maxIndex));

        // one form left and other from right 
        int left = min(minIndex, maxIndex)+1;
        int right = min(n-minIndex, n-maxIndex);
        result= min(result,left+right);
        return result;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();