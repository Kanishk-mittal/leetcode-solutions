#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int minWaterEnd = INT_MAX;
        int minLandEnd = INT_MAX;
        int land = landDuration.size();
        int water = waterDuration.size();
        for (int i = 0; i < land; i++)
        {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < water; i++)
        {
            minWaterEnd = min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
        }
        int result = INT_MAX;
        // starting with water
        for (int i = 0; i < land; i++)
        {
            result = min(result, max(minWaterEnd, landStartTime[i]) + landDuration[i]);
        }
        // starting with land
        for (int i = 0; i < water; i++)
        {
            result = min(result, max(minLandEnd, waterStartTime[i]) + waterDuration[i]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}