#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            bool rows[9] = {false}; // To track digits in each row
            bool cols[9] = {false}; // To track digits in each column
            bool box[9] = {false};  // To track digits in each 3x3 box
            for (int j = 0; j < 9; j++)
            {
                // Check row
                if (board[i][j] != '.')
                {
                    int rowIndex = board[i][j] - '1';
                    if (rows[rowIndex])
                        return false;
                    rows[rowIndex] = true;
                }
                // Check column
                if (board[j][i] != '.')
                {
                    int colIndex = board[j][i] - '1';
                    if (cols[colIndex])
                        return false;
                    cols[colIndex] = true;
                }
                // Check 3x3 box
                int rowIndex = 3 * (i / 3) + j / 3;
                int colIndex = 3 * (i % 3) + j % 3;
                if (board[rowIndex][colIndex] != '.')
                {
                    int boxIndex = board[rowIndex][colIndex] - '1';
                    if (box[boxIndex])
                        return false;
                    box[boxIndex] = true;
                }
            }
        }
        return true;
    }
};