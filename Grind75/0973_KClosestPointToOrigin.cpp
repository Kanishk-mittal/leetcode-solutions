#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    float dist(vector<int> &point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        sort(points.begin(), points.end(), [this](vector<int> a, vector<int> b)
             { return dist(a) < dist(b); });
        vector<vector<int>> result;
        result.reserve(k);
        for (int i = 0; i < k; i++)
        {
            result.push_back(points[i]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}