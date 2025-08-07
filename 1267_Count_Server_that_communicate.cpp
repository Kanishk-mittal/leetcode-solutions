# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        vector<int> row(grid.size(), 0);
        vector<int> col(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1))
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}