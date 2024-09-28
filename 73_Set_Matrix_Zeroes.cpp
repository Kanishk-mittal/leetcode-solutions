# include <iostream>
# include <vector>
# include <set>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> rows;
        set<int> columns;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        // setting rows as zero
        for (auto row : rows)
        {
            for (int i = 0; i < matrix[row].size(); i++)
            {
                matrix[row][i] = 0;
            }
        }
        // setting columns as zero
        for (auto column : columns)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][column] = 0;
            }
        }
    }
};