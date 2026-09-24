#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int digitSum(int n){
        int sum=0;
        while (n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (digitSum(nums[i])==i)
            {
                return i;
            }
        }
        return -1;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();