# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // bottom triangle sort 
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            int row=i, col=0;
            while(row<n && col<n)
            {
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end(), greater<int>());
            row=i, col=0;
            int k=0;
            while(row<n && col<n)
            {
                grid[row][col] = temp[k];
                row++;
                col++;
                k++;
            }
        }
        // upper triangle sort
        for (int i = 1; i < n; i++)
        {
            vector<int> temp;
            int row=0, col=i;
            while(row<n && col<n)
            {
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end());
            row=0, col=i;
            int k=0;
            while(row<n && col<n)
            {
                grid[row][col] = temp[k];
                row++;
                col++;
                k++;
            }
        }
        return grid;
    }
};

    int
    main(int argc, char const *argv[])
{
    
    return 0;
}