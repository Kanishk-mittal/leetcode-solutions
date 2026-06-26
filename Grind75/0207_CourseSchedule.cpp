#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(unordered_map<int, vector<int>> &adj, vector<bool> &onStack, vector<bool> &visited, int i)
    {
        if (onStack[i])
        {
            return false; // cycle detected
        }
        if (0 == adj[i].size() || visited[i])
        {
            return true; // we are on a leaf node
        }
        // mark current node as visited
        visited[i] = true;
        onStack[i] = true;
        bool result = true;
        for (int j = 0; j < adj[i].size(); j++)
        {
            result &= dfs(adj, onStack, visited, adj[i][j]);
        }
        onStack[i] = false;
        return result;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> onStack(numCourses);
        // buildign adj
        for (vector<int> p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i])
                continue;
            bool result = dfs(adj, onStack, visited, i);
            if (!result)
            {
                return false;
            }
        }
        return true;
    }
};
// this is a simple cycle detection in a directed graph

int main()
{
    Solution sol;
    return 0;
}