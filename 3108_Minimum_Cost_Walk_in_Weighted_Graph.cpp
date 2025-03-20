#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
private:
    int find(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        vector<int> parent(n);
        vector<int> cost(n,-1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            cost[i] = -1; // Initialize cost with -1 (invalid value)
        }
        // making components
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            int leader_u = find(parent, u);
            int leader_v = find(parent, v);

            if (leader_u != leader_v)
            {
                parent[leader_u] = leader_v;
            }
            parent[u] = leader_v;
            parent[v] = leader_v;
        }

        // calculating the cost
        for (auto &e : edges)
        {
            int root = find(parent, e[0]);
            cost[root]&=e[2];
        }

        vector<int> ans;
        for (auto &q : query)
        {
            if (find(parent, q[0]) == find(parent, q[1]))
            {
                ans.push_back(cost[find(parent, q[0])]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
    vector<vector<int>> query = {{0, 3}, {3, 4}};
    vector<int> result = sol.minimumCost(n, edges, query);

    for (int r : result)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
