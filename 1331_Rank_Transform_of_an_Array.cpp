#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = rank;
            rank++;
            while ((i + 1 < n) && arr[i] == arr[i + 1])
            {
                i++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            result[i] = mp[result[i]];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}