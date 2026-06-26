#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp; // this will store the index of all those position where we have same element
        for (int i = n - 1; i >= 0; i--)
        {
            mp[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int level = 0;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                if (q.front() == n - 1)
                {
                    return level;
                }
                if (q.front() + 1 < n && !visited[q.front() + 1])
                {
                    q.push(q.front() + 1);
                    visited[q.front() + 1] = true;
                }
                if (q.front() - 1 > 0 && !visited[q.front() - 1])
                {
                    q.push(q.front() - 1);
                    visited[q.front() - 1] = true;
                }
                if (mp.find(arr[q.front()]) != mp.end())
                {
                    for (int x : mp[arr[q.front()]])
                    {
                        if (!visited[x])
                        {
                            q.push(x);
                            visited[x] = true;
                        }
                    }
                }
                mp.erase(arr[q.front()]);
                q.pop();
            }
            level++;
        }
        return min(level, n);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 7, 7, 7, 7, 7, 11};
    cout << sol.minJumps(arr);
    return 0;
}