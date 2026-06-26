#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool hasElement(int l, int r)
    {
        return (*obs.upper_bound(l)) != r; // if the next obsticle
    }
    bool find(int size, int l, int r)
    {
        return true;
    }
    set<int> obs;

public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {
        for (vector<int> q : queries)
        {
            if (1 == q[0])
            {
                obs.insert(q[1]);
            }
            else
            {
            }
        }
    }
};

int main()
{
    Solution sol;
    return 0;
}