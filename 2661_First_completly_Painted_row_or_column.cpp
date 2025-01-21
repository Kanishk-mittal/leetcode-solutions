# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> positions(m*n+1,0);
        for (int i = 0; i < arr.size(); i++)
        {
            positions[arr[i]] = i;  
        }
        // replace the values of the matrix with the position of the element in the arr
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = positions[mat[i][j]];
            }
        }
        // find the row with minimum max element
        int minMax = INT_MAX;
        // find max element of each row
        for (int i = 0; i < n; i++)
        {
            int maxElement = INT_MIN;
            for (int j = 0; j < m; j++)
            {
                maxElement = max(maxElement, mat[i][j]);
            }
            if (maxElement < minMax)
            {
                minMax = maxElement;
            }
        }
        // find max element of each column
        for (int i = 0; i < m; i++)
        {
            int maxElement = INT_MIN;
            for (int j = 0; j < n; j++)
            {
                maxElement = max(maxElement, mat[j][i]);
            }
            if (maxElement < minMax)
            {
                minMax = maxElement;
            }
        }
        return minMax;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}