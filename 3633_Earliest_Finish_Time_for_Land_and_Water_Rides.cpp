#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int minTime = INT_MAX;
        // simple brute force
        int land = landDuration.size();
        int water = waterDuration.size();
        for (int i = 0; i < land; i++)
        {
            for (int j = 0; j < water; j++)
            {
                // land first
                int completionTime = max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j];
                minTime = min(minTime, completionTime);
                // water first
                completionTime = max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i];
                minTime = min(minTime, completionTime);
            }
        }
        return minTime;
    }
};

int main()
{
    Solution sol;
    return 0;
}