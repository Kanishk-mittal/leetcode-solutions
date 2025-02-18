# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int dfsUtil(vector<vector<int>> &grid, int x, int y, int direction, bool hasTurned, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        int size = 1;
        vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        if (hasTurned)
        {
            int newX = x + directions[direction][0];
            int newY = y + directions[direction][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != 1 && visited[newX][newY] == 0)
            {
                int temp = 1 + dfsUtil(grid, newX, newY, direction, hasTurned, visited);
                visited[newX][newY] = 1;
                size = max(size, temp);
            }
            else
            {
                return size;
            }
        }
        
        for (int k = 0; k < 4; k++)
        {
            int newX = x + directions[k][0];
            int newY = y + directions[k][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != 1 && visited[newX][newY] == 0)
            {
                int temp = 1 + dfsUtil(grid, newX, newY,k , direction!=k, visited);
                visited[newX][newY] = 1;
                size = max(size, temp);
            }
        }
        return size;
    }
public:
    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> directions={{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==1)
                {
                    vector<vector<int>> visited(n, vector<int>(m, 0));
                    for (int k = 0; k < 4; k++)
                    {
                        int newX=i+directions[k][0];
                        int newY=j+directions[k][1];
                        if (newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]!=1)
                        {
                            int size=dfsUtil(grid, newX, newY, k,false, visited);
                            ans=max(ans, size+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

    int
    main(int argc, char const *argv[])
{
    
    return 0;
}