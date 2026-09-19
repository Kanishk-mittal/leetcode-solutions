#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//============================
// O(n**2) solution
// will be accepted on leetcode
//============================
// class Solution {
// private:
//     /**
//      * find square of euclidian distance between two points
//      *
//      * @param x1 x co-cordinate of first point
//      * @param y1 y co-ordinate of first point
//      * @param x2 x co-cordinate of first point
//      * @param y2 y co-ordinate of first point
//      * @return return square of euclidian distance
//      */
//     long long distance(long long x1, long long y1, long long x2, long long y2){
//         return ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
//     }
// public:
//     bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
//         // Since the co-ordinates of square are in range 1e4 maybe we can try all points in the square
//         for (int x = x1; x <= x2; x++)
//         {
//             for (int y = y1; y <= y2; y++)
//             {
//                 if (distance(xCenter, yCenter, x,y)<=(1LL* radius*radius))
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

//============================
// O(n) solution
// if possible why not
//============================
class Solution {
private:
    pair<int,int> getRange(int r, int x, int xc, int yc){
        long long v1= 1LL*r*r;
        long long v2 = 1LL*(x-xc)*(x-xc);
        if (v1<v2)
        {
            return {INT_MIN, INT_MIN}; // this is not possible at all 
        }
        int d= sqrt(v1-v2);
        return {yc-d,yc+d};
    }
    bool hasOverlap(pair<int,int> r1, pair<int,int> r2){
        if (r1.first>r2.second || r2.first> r1.second)
        {
            return false;
        }
        return true;
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // here our target is to find if there is y for a fixed x which lies on the circle
        // will be using sqrt so wanter to avoid this 
        for (int x =x1 ; x <= x2; x++)
        {
            if (hasOverlap(
                getRange(radius,x,xCenter, yCenter),
                {y1,y2}
            ))
            {
                return true;
            }
        }
        return false;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();