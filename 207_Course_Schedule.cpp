# include <iostream>
# include <vector>
# include <unordered_map>
# include <queue>

using namespace std;

class Solution
{
private:
    bool dfs(unordered_map<int, vector<int>> &prerequisites, vector<int> &visited, int i)
    {
        // this function traverses the graph and returns false if a cycle is detected
        if (visited[i] == 1){
            return false;
        }
        if (visited[i] == 2){
            return true;
        }
        visited[i] = 1;
        for (int j : prerequisites[i]){
            if (!dfs(prerequisites, visited, j)){
                return false;
            }
        }
        visited[i] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> prerequisites_map;
        for (auto &p : prerequisites){
            prerequisites_map[p[0]].push_back(p[1]);
        }
        vector<int>visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++){
            if (!dfs(prerequisites_map, visited, i)){
                return false;
            }
        }
        return true;
    }
};