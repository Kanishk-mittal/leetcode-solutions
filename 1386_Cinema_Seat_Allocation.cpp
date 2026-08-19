#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int groupCount(const vector<bool> &row)
    {
        // we will get a row now we have to simply find the number of groups we can have here
        bool left = !(row[1] || row[2] || row[3] || row[4]);
        bool middle = !(row[3] || row[4] || row[5] || row[6]);
        bool right = !(row[5] || row[6] || row[7] || row[8]);
        if (left && right)
        {
            return 2;
        }
        else if (left || right || middle)
        {
            return 1;
        }
        return 0;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, vector<bool>> mp;
        for (vector<int> &seat : reservedSeats)
        {
            if (mp.find(seat[0]) == mp.end())
            {
                // first time finding this row
                mp[seat[0]] = vector<bool>(10);
            }
            mp[seat[0]][seat[1] - 1] = true;
        }
        int emptyRows = n - mp.size();
        int remaining = 0;
        for (const pair<int, vector<bool>> &i : mp)
        {
            remaining += groupCount(i.second);
        }
        return (emptyRows * 2) + remaining;
    }
};

int main()
{
    Solution sol;
    return 0;
}