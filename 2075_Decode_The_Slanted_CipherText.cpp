#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        int n = encodedText.size();
        int col = n / rows;
        vector<vector<char>> mat(col, vector<char>(rows));
        int idx = 0;
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                mat[i][j] = encodedText[idx];
                idx++;
            }
        }
        string msg = "";
        for (int c = 0; c < (col - rows) + 1; c++)
        {
            for (int r = 0; r < rows; r++)
            {
                msg = msg + mat[r][c + r];
            }
        }
        return msg;
    }
};

int main()
{
    Solution sol;
    string encodedText = "ch   ie   pr";
    int rows = 3;
    string decodedText = sol.decodeCiphertext(encodedText, rows);
    cout << "Decoded Text: " << decodedText << endl; // Output: "cipher"
    return 0;
}