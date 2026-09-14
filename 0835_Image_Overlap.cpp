#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int result = 0;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int overlap1 = 0; // img1 shifted down i, right j
                int overlap2 = 0; // img1 shifted up i, left j
                int overlap3 = 0; // img1 shifted down i, left j
                int overlap4 = 0; // img1 shifted up i, right j

                for (int k = 0; k < n - i; k++) {
                    for (int l = 0; l < n - j; l++) {
                        // 1. Down & Right
                        if (img1[k][l] == 1 && img2[k + i][l + j] == 1) overlap1++;
                        
                        // 2. Up & Left
                        if (img2[k][l] == 1 && img1[k + i][l + j] == 1) overlap2++;
                        
                        // 3. Down & Left
                        if (img1[k][l + j] == 1 && img2[k + i][l] == 1) overlap3++;
                        
                        // 4. Up & Right
                        if (img2[k][l + j] == 1 && img1[k + i][l] == 1) overlap4++;
                    }
                }

                result = max({result, overlap1, overlap2, overlap3, overlap4});
            }
        }

        return result;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 0;
}();

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> img1={
        {1,0},
        {0,0}
    };
    vector<vector<int>> img2={
        {0,1},
        {1,0}
    };
    cout<<sol.largestOverlap(img1,img2)<<endl;
    return 0;
}
