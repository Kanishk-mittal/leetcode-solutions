#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n <= 2)
        {
            vector<int> result;
            for (int i = 0; i < n; i++)
            {
                result.push_back(i);
            }
            return result;
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (vector<int> e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (1 == degree[i])
            {
                q.push(i);
            }
        }
        int remaining = n;
        while (remaining > 2)
        {
            int leafs = q.size();
            remaining -= leafs;
            for (int i = 0; i < leafs; i++)
            {
                int leaf = q.front();
                q.pop();
                for (int x : adj[leaf])
                {
                    degree[x]--;
                    if (degree[x] == 1)
                    {
                        q.push(x);
                    }
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}

/*
it contain only 2*1e4 nodes so we can use multipoint dfs to find the height of the tree from each node and find the minimum height and return the nodes with minimum height
*/