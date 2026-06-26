#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int k)
    {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k])
        {
            return false;
        }
        if (k == word.size() - 1)
        {
            return true;
        }
        char tmp = board[i][j];
        board[i][j] = '/';
        bool res = dfs(board, i + 1, j, word, k + 1) || dfs(board, i - 1, j, word, k + 1) || dfs(board, i, j + 1, word, k + 1) || dfs(board, i, j - 1, word, k + 1);
        board[i][j] = tmp;
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // find the first character of word in board
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (dfs(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    return 0;
}