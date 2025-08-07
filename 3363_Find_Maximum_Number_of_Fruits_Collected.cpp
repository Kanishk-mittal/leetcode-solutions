# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    // Simple 2D memoization matrix initialized with -1
    vector<vector<int>> memo;

    
    int getMaxFruits(int x, int y, vector<vector<int>> &fruits, int stepsRemaining, vector<vector<int>> &allowedMoves)
    {
        // Check if we already computed max fruits from this position
        if (memo[x][y] != -1) {
            return memo[x][y];
        }
        
        // this function will return the max fruits one can get and will set them as 0 also and use itself recursively return -1 if that path is not possible
        // base case
        if (stepsRemaining == 0)
        {
            if (x == fruits.size() - 1 && y == fruits.size() - 1)
            {
                memo[x][y] = 0; // Store in memo
                return 0;
            }
            else
            {
                memo[x][y] = -2; // Store in memo (impossible path)
                return -2;
            }
        }
        if(x==y){
            memo[x][y] = -2; // Store in memo (impossible path)
            return -2;
        }
        // now try all possible paths recursively
        int maxResult = -2;
        for (int i = 0; i < 3; i++)
        {
            if (x + allowedMoves[i][0] < fruits.size() && x + allowedMoves[i][0] >= 0 && y + allowedMoves[i][1] < fruits.size() && y + allowedMoves[i][1] >= 0)
            {
                int temp = getMaxFruits(x + allowedMoves[i][0], y + allowedMoves[i][1], fruits, stepsRemaining - 1, allowedMoves);
                if (temp > maxResult)
                {
                    maxResult = temp;
                }
            }
        }
        if (maxResult < 0)
        {
            memo[x][y] = -2; // Store in memo (impossible path)
            return -2;
        }
        maxResult += fruits[x][y];
        memo[x][y] = maxResult; // Store in memo
        return maxResult;
    }

public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        // Initialize memoization matrix with -1
        int n = fruits.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        
        // first adding all the digonal elements and then setting them as 0
        int total_sum = 0;
        for (int i = 0; i < fruits.size(); i++)
        {
            total_sum += fruits[i][i];
            fruits[i][i] = 0;
        }
        // allowed moves
        vector<vector<int>> allowedBottomLeft = {{1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> allowedTopRight = { {-1, 1},
                                                {0, 1},
                                                {1, 1} };
        // finding them one by one first first bottom left
        int bottomLeft = getMaxFruits(0, fruits.size() - 1, fruits, fruits.size() - 1, allowedBottomLeft);
        
        // Reset memoization for fresh computation of top right path
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        
        int topRight = getMaxFruits(fruits.size() - 1, 0, fruits, fruits.size() - 1, allowedTopRight);
            // no need to set them as zero
            total_sum += bottomLeft + topRight;
        return total_sum;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}