#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>freq(10,0);
        for(int i : digits){
            freq[i]++;
        }
        int count=0;
        for (int i = 100; i < 1000; i++)
        {
            vector<int>temp(10,0);
            temp[i%10]++;
            temp[(i%100)/10]++;
            temp[(i%1000)/100]++;
            if (
                temp[i%10] <=freq[i%10] &&
                temp[(i%100)/10] <=freq[(i%100)/10] &&
                temp[(i%1000)/100] <=freq[(i%1000)/100]
            )
            {
                count++;
            }
        }
        return count;
        
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
    vector<int> temp = {1,2,3,4};
    cout<<sol.totalNumbers(temp)<<endl;
    return 0;
}
