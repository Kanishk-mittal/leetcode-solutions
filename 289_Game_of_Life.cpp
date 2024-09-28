# include <iostream>
# include <vector>
using namespace std;
class Solution
{
private:
    int countLive(const vector<vector<int>> &board, int i, int j)
    {
        int count = 0;
        for (int x = i - 1; x <= i + 1; x++)
        {
            for (int y = j - 1; y <= j + 1; y++)
            {
                if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && !(x == i && y == j) && board[x][y] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> swap_index;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                int liveNeighbors = countLive(board, i, j);

                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                {
                    swap_index.push_back({i, j});
                }
                else if (board[i][j] == 0 && liveNeighbors == 3)
                {
                    swap_index.push_back({i, j});
                }
            }
        }

        for (const auto &index : swap_index)
        {
            int i = index[0], j = index[1];
            board[i][j] = 1 - board[i][j]; // Flip the state
        }
    }
};