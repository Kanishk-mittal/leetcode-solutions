# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int i)
    {
        if (color[i] > 0)
        {
            return color[i] == 2;
        }
        color[i] = 1;
        for (int j : graph[i])
        {
            if (color[j] == 2)
            {
                continue;
            }
            if (color[j] == 1 || !dfs(graph, color, j))
            {
                return false;
            }
        }
        color[i] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), 0);
        vector<int> res;
        for (int i = 0; i < graph.size(); i++)
        {
            if (dfs(graph, color, i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}