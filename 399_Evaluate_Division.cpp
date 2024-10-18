# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>

using namespace std;

class Solution
{
private:
    double dfs(unordered_map<string, unordered_map<string, double>> &graph, string a, string b, unordered_set<string> &visited)
    {
        if (a == b)
        {
            return 1.0;
        }
        visited.insert(a);
        for (auto &neighbor : graph[a])
        {
            if (visited.count(neighbor.first))
            {
                continue;
            }
            double t = dfs(graph, neighbor.first, b, visited);
            if (t > 0)
            {
                return t * neighbor.second;
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double k = values[i];
            graph[a][b] = k;
            graph[b][a] = 1.0 / k;
        }
        vector<double> res;
        for (auto &query : queries)
        {
            string a = query[0];
            string b = query[1];
            if (!graph.count(a) || !graph.count(b))
            {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double t = dfs(graph, a, b, visited);
            res.push_back(t);
        }
        return res;
    }
};