# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>> pq;  // {height, x, y}
        // Push the boundary into the priority queue
        for (int i = 0; i < n; i++)
        {
            pq.push({-heightMap[i][0], i, 0});
            pq.push({-heightMap[i][m - 1], i, m - 1});
            visited[i][0] = visited[i][m - 1] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            pq.push({-heightMap[0][i], 0, i});
            pq.push({-heightMap[n - 1][i], n - 1, i});
            visited[0][i] = visited[n - 1][i] = 1;
        }
        // all the boundary cells are visited now we will start from the smallest height cell
        int trappedWater = 0;
        int maxHeight = 0; // This will be updated whenever we pop an element from the priority queue
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int height = -top[0], x = top[1], y = top[2];
            maxHeight = max(maxHeight, height);
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    if (heightMap[nx][ny] < maxHeight)
                    {
                        trappedWater += maxHeight - heightMap[nx][ny];
                    }
                    pq.push({-heightMap[nx][ny], nx, ny});
                }
            }
        }
        return trappedWater;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}