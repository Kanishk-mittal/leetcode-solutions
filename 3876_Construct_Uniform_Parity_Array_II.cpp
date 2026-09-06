#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        /**
         * Either of the following need to be true 
         * no even element 
         * no odd element
         * convert all even to odd -> there shoudl be a odd number less than that
         * conver all odd to even  -> there shoudl be a odd number less than it (not possible how will we get an odd number smaller than the smallest odd number)
         */
        int n = nums1.size();
        bool allEven=true;
        bool allOdd=true;
        int minEven=INT_MAX;
        int minOdd=INT_MAX;
        for (int i : nums1)
        {
            if (i%2==0)
            {
                allOdd=false;
                minEven=min(minEven,i);
            }else{
                allEven=false;
                minOdd=min(minOdd, i);
            }
        }
        
        if (allOdd || allEven)
        {
            return true;
        }
        return minEven-minOdd>=1;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();