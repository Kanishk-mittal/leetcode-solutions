#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
private:
    // Function to find the diameter of a tree
    int getDiameter(vector<vector<int>> &adj, int n)
    {
        // BFS to find the farthest node from node 0
        queue<int> q;
        vector<int> dist(n, -1);
        dist[0] = 0;
        q.push(0);

        int farthestNode = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node])
            {
                if (dist[neighbour] == -1)
                {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                    if (dist[neighbour] > dist[farthestNode])
                    {
                        farthestNode = neighbour;
                    }
                }
            }
        }

        // BFS from the farthest node found to calculate the actual diameter
        fill(dist.begin(), dist.end(), -1);
        dist[farthestNode] = 0;
        q.push(farthestNode);

        int diameter = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node])
            {
                if (dist[neighbour] == -1)
                {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                    diameter = max(diameter, dist[neighbour]);
                }
            }
        }

        return diameter;
    }

    // Function to find the center of a tree
    int getCenter(vector<vector<int>> &adj, int n)
    {
        vector<int> degree(n, 0);
        queue<int> leaves;

        // Find all leaves (nodes with degree 1)
        for (int i = 0; i < n; ++i)
        {
            degree[i] = adj[i].size();
            if (degree[i] == 1)
            {
                leaves.push(i);
            }
        }

        int remainingNodes = n;

        // Remove leaves layer by layer
        while (remainingNodes > 2)
        {
            int numLeaves = leaves.size();
            remainingNodes -= numLeaves;

            for (int i = 0; i < numLeaves; ++i)
            {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adj[leaf])
                {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                    {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        // The remaining nodes are the center(s)
        return leaves.front();
    }

    // Function to calculate the max distance from the center node
    int getMaxDistanceFromCenter(vector<vector<int>> &adj, int n, int center)
    {
        queue<int> q;
        vector<int> dist(n, -1);
        dist[center] = 0;
        q.push(center);

        int maxDist = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node])
            {
                if (dist[neighbour] == -1)
                {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                    maxDist = max(maxDist, dist[neighbour]);
                }
            }
        }

        return maxDist;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        // Build adjacency lists for both trees
        int size1 = edges1.size() + 1;
        int size2 = edges2.size() + 1;

        if (size1 == 1 && size2 == 1)
        {
            return 1;
        }

        // If one tree has only 0 node, the merged diameter will be the diameter of the other tree plus 1 
        if (size1 == 1)
        {
            vector<vector<int>> adj2(size2);
            for (auto &edge : edges2)
            {
                adj2[edge[0]].push_back(edge[1]);
                adj2[edge[1]].push_back(edge[0]);
            }
            int diameter2 = getDiameter(adj2, size2);
            int center2 = getCenter(adj2, size2);
            int maxDistance2 = getMaxDistanceFromCenter(adj2, size2, center2);
            return max(diameter2, maxDistance2 + 1);
        }
        if (size2 == 1)
        {
            vector<vector<int>> adj1(size1);
            for (auto &edge : edges1)
            {
                adj1[edge[0]].push_back(edge[1]);
                adj1[edge[1]].push_back(edge[0]);
            }
            int diameter1 = getDiameter(adj1, size1);
            int center1 = getCenter(adj1, size1);
            int maxDistance1 = getMaxDistanceFromCenter(adj1, size1, center1);
            return max(diameter1, maxDistance1 + 1);
        }

        vector<vector<int>> adj1(size1);
        vector<vector<int>> adj2(size2);

        for (auto &edge : edges1)
        {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (auto &edge : edges2)
        {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // Get the diameters of both trees
        int diameter1 = getDiameter(adj1, size1);
        int diameter2 = getDiameter(adj2, size2);

        // Get the centers of both trees
        int center1 = getCenter(adj1, size1);
        int center2 = getCenter(adj2, size2);

        // Get the max distance from the centers to the farthest leaf
        int maxDistance1 = getMaxDistanceFromCenter(adj1, size1, center1);
        int maxDistance2 = getMaxDistanceFromCenter(adj2, size2, center2);

        

        // Calculate the new diameter
        int ans = max(diameter1, diameter2);             // Max of both diameters
        ans = max(ans, maxDistance1 + 1 + maxDistance2); // Adding the center distance (1 unit) between trees

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges1 = {};
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}};

    Solution sol;
    cout << sol.minimumDiameterAfterMerge(edges1, edges2) << endl;

    return 0;
}
