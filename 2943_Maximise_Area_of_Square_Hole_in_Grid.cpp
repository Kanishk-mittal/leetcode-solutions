#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        // find the longest continious
        // first for hBars
        int longestH = 1;
        int last = 0;
        for (int i = 0; i < hBars.size(); i++)
        {
            int temp = 2;
            while (hBars[i] == last + 1)
            {
                last = hBars[i];
                temp++;
            }
            last = hBars[i];
            longestH = max(longestH, temp);
        }
        int longestV = 1;
        last = 0;
        for (int i = 0; i < vBars.size(); i++)
        {
            int temp = 2;
            while (vBars[i] == last + 1)
            {
                last = vBars[i];
                temp++;
            }
            last = vBars[i];
            longestV = max(longestV, temp);
        }
        return min(longestV, longestH) * min(longestV, longestH);
    }
};

int main()
{
    Solution sol;
    int n = 4, m = 4;
    vector<int> hBars = {2, 3, 4, 5};
    vector<int> vBars = {5, 4, 3, 2};
    cout << sol.maximizeSquareHoleArea(n, m, hBars, vBars) << endl; // Output: 9
    return 0;
}