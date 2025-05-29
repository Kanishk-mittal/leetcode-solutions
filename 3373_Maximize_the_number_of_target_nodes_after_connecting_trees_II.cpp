# include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> get_adjacency_list(vector<vector<int>> &edge_list)
    {
        // Find the maximum node ID to ensure the adjacency list is large enough
        int max_node_id = 0;
        for (const auto &edge : edge_list)
        {
            max_node_id = max(max_node_id, max(edge[0], edge[1]));
        }

        // Initialize adjacency list with size max_node_id + 1 to accommodate all nodes
        vector<vector<int>> adj(max_node_id + 1);
        for (const auto &edge : edge_list)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // assuming undirected tree
        }
        return adj;
    }
    int number_of_targets(vector<vector<int>> &adj, int level, int node, vector<bool> &visited)
    {
        // base case
        if (level < 0 || node >= adj.size())
            return 0;
        visited[node] = true;
        int count;
        if (level% 2 == 0)
        {
            count = 1; // count this node as a target
        }
        else
        {
            count = 0; // do not count this node as a target
        }
        
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                count += number_of_targets(adj, level + 1, neighbor, visited);
            }
        }
        return count;
    }
    void bfs(
        vector<vector<int>> &adj,
        int node,
        int level,
        int odd_count,
        int even_count,
        int max_2,
        vector<bool> & visited,
        vector<int> &result)
    {
        // base case
        if (node >= adj.size())
            return;
        visited[node] = true;
        if (level % 2 == 0)
        {
            result[node] = even_count + max_2;
            cout << "Even count for node " << node << ": " << even_count + max_2 << endl;
        }
        else
        {
            result[node] = odd_count + max_2;
            cout << "Odd count for node " << node << ": " << odd_count + max_2 << endl;
        }
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                bfs(adj, neighbor, level + 1, odd_count, even_count, max_2, visited, result);
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        vector<vector<int>> adj1 = get_adjacency_list(edges1);
        vector<vector<int>> adj2 = get_adjacency_list(edges2);
        int n = adj1.size();
        int m = adj2.size();
        vector<int> result(n, 0);
        // for each node we will calculate even count and odd count
        int even_count_1 = 0, odd_count_1 = 0;
        vector<bool> visited1(n, false);
        even_count_1 = number_of_targets(adj1, 0, 0, visited1);
        visited1.assign(n, false); // Reset visited for odd count

        //find an adjacent node to 0
        int odd_node = adj1[0][0];
        odd_count_1 = number_of_targets(adj1, 0, odd_node, visited1);

        // doing the same for adj2
        int even_count_2 = 0, odd_count_2 = 0;
        vector<bool> visited2(m, false);
        even_count_2 = number_of_targets(adj2, 0, 0, visited2);
        visited2.assign(m, false); // Reset visited for odd count

        //find an adjacent node to 0
        int odd_node2 = adj2[0][0];
        odd_count_2 = number_of_targets(adj2, 0, odd_node2, visited2);

        // now we will calculate the result for each node in adj1
        int max2=max(even_count_2, odd_count_2);
        cout << "Max of even and odd count in adj1: " << max2 << endl;

        visited1.assign(n, false); // Reset visited for BFS
        bfs(adj1, 0, 0, odd_count_1, even_count_1, max2, visited1, result);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
    Solution sol;
    vector<int> result = sol.maxTargetNodes(edges1, edges2);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "Node " << i << ": " << result[i] << " targets" << endl;
    }
    return 0;
}