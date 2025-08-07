#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> moves(n * n + 1, -1); // flattened board
        bool flip = false;
        int idx = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!flip)
            {
                for (int j = 0; j < n; j++)
                {
                    moves[idx++] = board[i][j];
                }
            }
            else
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    moves[idx++] = board[i][j];
                }
            }
            flip = !flip;
        }

        vector<int> visited(n * n + 1, 0);
        queue<pair<int, int>> q; // (current position, moves count)
        q.push({1, 0});
        visited[1] = 1;

        while (!q.empty())
        {
            int curr = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (curr == n * n)
            {
                return steps;
            }

            for (int k = 1; k <= 6; k++)
            {
                int next = curr + k;
                if (next > n * n)
                    break;

                if (moves[next] != -1)
                {
                    next = moves[next];
                }

                if (!visited[next])
                {
                    visited[next] = 1;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};
