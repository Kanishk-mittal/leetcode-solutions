#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {}; // Handle empty matrix

        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();
        vector<int> result;

        while (left < right && top < bottom)
        {
            // Move right
            for (int i = left; i < right; ++i)
            {
                result.push_back(matrix[top][i]);
            }
            top++;

            // Move down
            for (int i = top; i < bottom; ++i)
            {
                result.push_back(matrix[i][right - 1]);
            }
            right--;

            // Check if there is a remaining row
            if (top >= bottom)
                break;

            // Move left
            for (int i = right - 1; i >= left; --i)
            {
                result.push_back(matrix[bottom - 1][i]);
            }
            bottom--;

            // Check if there is a remaining column
            if (left >= right)
                break;

            // Move up
            for (int i = bottom - 1; i >= top; --i)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }

        return result;
    }
};