#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    // Check if a component is bipartite and return nodes in the component
    bool isComponentBipartite(vector<vector<int>> &adj, int src, vector<int> &color, vector<int> &component)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        component.push_back(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (color[neighbor] == 0)
                {
                    color[neighbor] = -color[node];
                    q.push(neighbor);
                    component.push_back(neighbor);
                }
                else if (color[neighbor] == color[node])
                {
                    return false; // Not bipartite
                }
            }
        }
        return true;
    }

    // Run BFS and find the longest level-order traversal starting from 'start'
    int getMaxDepth(vector<vector<int>> &adj, int start, int n)
    {
        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int levels = 0;

        while (!q.empty())
        {
            int size = q.size();
            levels++;
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
        return levels;
    }

public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        // Create adjacency list (1-indexed)
        vector<vector<int>> adj(n + 1);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0);
        int maxGroups = 0;

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                vector<int> component;
                if (!isComponentBipartite(adj, i, color, component))
                {
                    return -1; // Not bipartite
                }

                // Find the maximum BFS depth for this component
                int maxDepth = 0;
                for (int node : component)
                {
                    maxDepth = max(maxDepth, getMaxDepth(adj, node, n));
                }
                maxGroups += maxDepth;
            }
        }

        return maxGroups;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << sol.magnificentSets(5, edges) << endl; // Expected Output: 3
    return 0;
}
