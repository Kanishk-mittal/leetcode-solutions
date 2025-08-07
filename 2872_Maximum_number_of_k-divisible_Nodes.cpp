#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Nde
{
    int val;
    vector<Nde *> children;

    Nde(int x) : val(x), children({}) {}
};

class Solution
{
private:
    void dfs(Nde *node, int k, int &ans)
    {
        if (node->children.size() == 0)
        {
            if (node->val % k == 0)
            {
                ans++;
                node->val = 0;
            }
        }
        else
        {
            for (int i = 0; i < node->children.size(); i++)
            {
                dfs(node->children[i], k, ans);
                node->val += node->children[i]->val;
            }
            if (node->val % k == 0)
            {
                ans++;
                node->val = 0;
            }
        }
    }

    void dfsBuild(int node, int parent, vector<Nde *> &nodes, vector<vector<int>> &adj)
    {
        for (int neighbor : adj[node])
        {
            if (neighbor != parent)
            {
                nodes[node]->children.push_back(nodes[neighbor]);
                dfsBuild(neighbor, node, nodes, adj);
            }
        }
    }

public:
    Nde *buildTree(vector<vector<int>> &edges, vector<int> &values)
    {
        vector<Nde *> nodes(values.size());
        for (int i = 0; i < values.size(); i++)
        {
            nodes[i] = new Nde(values[i]);
        }

        vector<vector<int>> adj(values.size());
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfsBuild(0, -1, nodes, adj);
        return nodes[0];
    }

    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        Nde *root = buildTree(edges, values);
        int ans = 0;
        dfs(root, k, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values = {1, 8, 1, 4, 4};
    int k = 6;
    cout << sol.maxKDivisibleComponents(n, edges, values, k) << endl;
    return 0;
}
