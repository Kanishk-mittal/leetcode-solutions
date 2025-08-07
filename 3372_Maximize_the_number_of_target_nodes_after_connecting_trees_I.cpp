# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> get_adjacency_list(vector<vector<int>>&edge_list){
        // Find the maximum node ID to ensure the adjacency list is large enough
        int max_node_id = 0;
        for (const auto& edge : edge_list) {
            max_node_id = max(max_node_id, max(edge[0], edge[1]));
        }
        
        // Initialize adjacency list with size max_node_id + 1 to accommodate all nodes
        vector<vector<int>> adj(max_node_id + 1);
        for (const auto& edge : edge_list) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // assuming undirected tree
        }
        return adj;
    }
    int maximum_targets(vector<vector<int>>&adj, int k, int node, vector<bool>&visited){
        // base case
        if (k < 0 || node >= adj.size()) return 0;
        visited[node] = true;
        int count = 1; // count this node as a target
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                count += maximum_targets(adj, k - 1, neighbor, visited);
            }
        }
        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        // creating adjacency list from given edges vector
        vector<vector<int>> adj1 = get_adjacency_list(edges1);
        vector<vector<int>> adj2 = get_adjacency_list(edges2);
        int n = adj1.size();
        int m = adj2.size();
        vector<int> result(n, 0); // Initialize with correct size
        
        // finding node in adj2 with maximum targets
        int max_targets = 0;
        for (int i = 0; i < m; ++i) {
            vector<bool> visited(m, false); // Size should be m, not n
            int targets = maximum_targets(adj2, k-1, i, visited);
            if (targets > max_targets) {
                max_targets = targets;
            }
        }

        // Add max_targets to each result element
        for (int i = 0; i < n; ++i) {
            result[i] = max_targets;
        }
        
        // finding out maximum targets for each node in adj1
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false); // Size should be n, not m
            int targets = maximum_targets(adj1, k, i, visited);
            result[i] += targets;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
    int k = 2;
    Solution sol;
    vector<int> result = sol.maxTargetNodes(edges1, edges2, k);
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << " targets" << endl;
    }
    return 0;
}