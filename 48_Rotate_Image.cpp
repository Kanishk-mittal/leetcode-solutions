# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // other digonal transpose
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size() - (i + 1); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - 1 - j][matrix.size() - 1 - i];
                matrix[matrix.size() - 1 - j][matrix.size() - 1 - i] = temp;
            }
        }
        // reverse
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - 1 - i][j];
                matrix[matrix.size() - 1 - i][j] = temp;
            }
        }
    }
};