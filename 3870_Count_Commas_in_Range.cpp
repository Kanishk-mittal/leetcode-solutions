#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// this is the fastest solution but will fail for higher number
// class Solution {
// public:
//     int countCommas(int n) {
//         return max(0,n-999);
//     }
// }; 

// this one is slower but will work on large number as well
// class Solution {
// private:
//     /**
//      * count numebr of commas in a number
//      *
//      * @param n number where we need to count commas
//      * @return number of commas
//      */
//     int count(int n){
//         int count=0;
//         while (n>0)
//         {
//             count++;
//             n/=1000;
//         }
//         return max(0,count -1);
//     }
// public:
//     int countCommas(int n) {
//         int result =0;
//         for (int i = 0; i < n+1; i++)
//         {
//             result+=count(i);
//         }
//         return result;
//     }
// };

// this one can handle really large numbers as well

class Solution {
public:
    long long countCommas(long long n) {
        long long commaCount=0;
        long long base=1000;
        while (n>=base)
        {
            commaCount+=(n-base+1);
            if (base>(LLONG_MAX/1000))
            {
                break;
            }
            base*=1000;
        }
        return commaCount;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();