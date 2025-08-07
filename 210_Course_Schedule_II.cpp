#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> prerequisites_map;
        vector<int> indegree(numCourses, 0);

        // Correctly populate the prerequisites map and in-degree vector
        for (auto &p : prerequisites)
        {
            prerequisites_map[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int i : prerequisites_map[course])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        if (order.size() == numCourses)
        {
            return order;
        }
        return {};
    }
};