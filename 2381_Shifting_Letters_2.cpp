# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    char shiftChar(char c, int shift)
    {
        int ascii = c - 'a';
        ascii = (ascii + shift) % 26;
        if (ascii < 0)
        {
            ascii += 26;
        }
        return ascii + 'a';
    }
    void calculateTotalShifts(vector<int> &totalShifts, vector<vector<int>> &shifts)
    {
        for (auto &shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 0 ? -1 : 1;

            // Apply the shifts to the prefix sum array
            totalShifts[start] += direction;
            if (end + 1 < totalShifts.size())
            {
                totalShifts[end + 1] -= direction;
            }
        }

        // Calculate prefix sums to propagate the shifts
        for (int i = 1; i < totalShifts.size(); i++)
        {
            totalShifts[i] += totalShifts[i - 1];
        }
    }

public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        vector<int> totalShifts(s.length(), 0);
        calculateTotalShifts(totalShifts, shifts);
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = shiftChar(s[i], totalShifts[i]);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "xuwdbdqik";
    vector<vector<int>> shifts = {{4, 8, 0}, {4, 4, 0}, {2, 4, 0}, {2, 4, 0}, {6, 7, 1}, {2, 2, 1}, {0, 2, 1}, {8, 8, 0}, {1, 3, 1}};
    cout << sol.shiftingLetters(s, shifts) << endl;
    return 0;
}