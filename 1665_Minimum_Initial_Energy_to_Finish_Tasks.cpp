#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b)
             { return (a[1] - a[0]) > (b[1] - b[0]); });
        int result = 0;
        int rem = 0;
        for (vector<int> &i : tasks)
        {
            if (rem < i[1])
            {
                int diff = i[1] - rem;
                result += diff;
                rem += diff;
            }
            rem -= i[0];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}