#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        int start;
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] != ' ')
            {
                start = i;
                break;
            }
        }
        for (int i = start; i >= 0; i--)
        {
            if ((s[i] == ' '))
            {
                break;
            }
            count++;
        }
        return count;
    }
};