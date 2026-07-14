#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (vector<int> edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            set<int> component;
            queue<int> q;
            q.push(i);
            component.insert(i);
            visited[i] = true;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int node : adj[curr])
                {
                    if (visited[node])
                    {
                        continue;
                    }
                    component.insert(node);
                    visited[node] = true;
                    q.push(node);
                }
            }
            int count = component.size();
            bool isComplete = true;
            for (int node : component)
            {
                if (adj[node].size() != count - 1)
                {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete)
            {
                result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}