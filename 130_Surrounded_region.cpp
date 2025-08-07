# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = 'T';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
public:
    void solve(vector<vector<char>> &board)
    {
        // capture O surroundded by X
        // traversing through the border and marking all the O's as 'T'
        if (board.size() == 0){
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
            if (board[i][cols - 1] == 'O')
            {
                dfs(board, i, cols - 1);
            }
        }
        for (int j = 0; j < cols; j++)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }
            if (board[rows - 1][j] == 'O')
            {
                dfs(board, rows - 1, j);
            }
        }
        // traversing through the board and marking all the O's as 'X' and 'T' as 'O'
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};