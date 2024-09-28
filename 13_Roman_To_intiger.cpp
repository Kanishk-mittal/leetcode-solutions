# include <iostream>
using namespace std;

class Solution
{
public:
    int value(char n)
    {
        if (n == 'I')
        {
            return 1;
        }
        else if (n == 'V')
        {
            return 5;
        }
        else if (n == 'X')
        {
            return 10;
        }
        else if (n == 'C')
        {
            return 100;
        }
        else if (n == 'D')
        {
            return 500;
        }
        else if (n == 'L')
        {
            return 50;
        }
        else if (n == 'M')
        {
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s)
    {
        int number = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (value(s[i]) >= value(s[i + 1]))
            {
                number += value(s[i]);
            }
            if (value(s[i]) < value(s[i + 1]))
            {
                number -= value(s[i]);
            }
        }
        number += value(s[s.size() - 1]);
        return number;
    }
};