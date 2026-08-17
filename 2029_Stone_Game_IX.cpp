#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        vector<int> cateogry(3, 0);
        for (int i : stones)
        {
            cateogry[i % 3]++;
        }
        if (cateogry[0] % 2 == 0)
        {
            return cateogry[1] > 0 && cateogry[2] > 0;
        }
        return abs(cateogry[1] - cateogry[2]) > 2;
    }
};

int main()
{
    Solution sol;
    return 0;
}