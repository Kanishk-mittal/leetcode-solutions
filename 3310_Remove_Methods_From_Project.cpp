#include <vector>
#include <queue>
#include <numeric>

class Solution
{
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>> &invocations)
    {
        // Construct adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto &inv : invocations)
        {
            adj[inv[0]].push_back(inv[1]);
        }

        // 1. BFS to identify all suspicious methods starting from k
        std::vector<bool> isSuspicious(n, false);
        std::queue<int> q;

        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr])
            {
                if (!isSuspicious[neighbor])
                {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // 2. Check if any non-suspicious node invokes a suspicious node
        bool externalInvocationFound = false;
        for (int u = 0; u < n; u++)
        {
            if (!isSuspicious[u]) // Only check non-suspicious nodes
            {
                for (int v : adj[u])
                {
                    if (isSuspicious[v])
                    {
                        externalInvocationFound = true;
                        break;
                    }
                }
            }
            if (externalInvocationFound)
            {
                break;
            }
        }

        // 3. Prepare the result based on the check
        std::vector<int> result;

        if (externalInvocationFound)
        {
            // Cannot remove suspicious methods; return all methods [0, n-1]
            result.resize(n);
            std::iota(result.begin(), result.end(), 0);
        }
        else
        {
            // Return only non-suspicious methods
            for (int i = 0; i < n; i++)
            {
                if (!isSuspicious[i])
                {
                    result.push_back(i);
                }
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