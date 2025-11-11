#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int sumUpto(int n) { return (n * (n + 1)) / 2; }
    int operationsNeeded(int lower, int upper)
    {
        int lowerN = (lower / 4) + 1;
        int upperN = (upper / 4) + 1;
        if (lowerN == upperN)
        {
            return (upper % 4) - (lower % 4) + 1;
        }
        int left = (4 - (lower % 4)) * lowerN;
        int right = ((upper % 4) + 1) * upperN;
        int middle = sumUpto(upperN - 1) - sumUpto(lowerN);
        int operations = (left + (middle * 4) + right);
        return (max(upperN, operations));
    }

public:
    long long minOperations(vector<vector<int>> &queries)
    {
        int total = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            total += ceil(operationsNeeded(queries[i][0], queries[i][1]) / 2.0);
        }
        return total;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> queries = {{3, 10}};
    cout << obj.minOperations(queries) << endl; // expected is 8
    return 0;
}