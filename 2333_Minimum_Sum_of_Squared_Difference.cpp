#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size();
        priority_queue<long long> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        long long moves = k1 + k2;
        for (pair<int, int> pr : mp)
        {
            pq.push(pr.first);
        }
        while (moves > 0 && pq.top() > 0)
        {
            int curr = pq.top();
            pq.pop();
            if (mp[curr]==0)
            {
                continue;
            }
            int red= min(moves, 1LL*mp[curr]);
            mp[curr]-=red;
            mp[curr-1]+=red;
            pq.push(curr-1);
            moves-=red;
        }
        // finaly result computation
        long long result = 0;
        for (pair<int, int> pr : mp)
        {
            result += (1LL * pr.first * pr.first) * pr.second;
        }
        return result;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();