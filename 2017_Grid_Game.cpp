# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        vector<long long> prefixTop(n, 0), prefixBottom(n, 0);

        // Compute prefix sums for the top and bottom rows
        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];
        for (int i = 1; i < n; i++)
        {
            prefixTop[i] = prefixTop[i - 1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i - 1] + grid[1][i];
        }

        long long result = LLONG_MAX;

        // Consider each column as the potential split point
        for (int i = 0; i < n; i++)
        {
            // Robot 1 chooses the top row up to column i
            // Robot 2 takes the remaining top row and all of the bottom row
            long long scoreTop = (i == n - 1) ? 0 : prefixTop[n - 1] - prefixTop[i];
            long long scoreBottom = (i == 0) ? 0 : prefixBottom[i - 1];

            // Robot 2 will minimize the maximum of the two scores
            long long secondRobotScore = max(scoreTop, scoreBottom);

            // Minimize Robot 2's best achievable score
            result = min(result, secondRobotScore);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}