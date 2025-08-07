# include <iostream>
# include <vector>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        string arr[numRows];
        int j = 0;
        int reverse = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (j == (numRows - 1))
            {
                reverse = 1;
            }
            else if (j == 0)
            {
                reverse = 0;
            }
            arr[j] += s[i];
            if (reverse)
            {
                j--;
            }
            else
            {
                j++;
            }
        }
        string return_str = "";
        for (int i = 0; i < numRows; i++)
        {
            return_str += arr[i];
        }
        return return_str;
    }
};