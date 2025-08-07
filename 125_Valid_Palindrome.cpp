# include <iostream>
# include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string normal_s;
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                normal_s += tolower(s[i]); // Convert to lowercase and append to normal_s
            }
        }

        int left = 0;
        int right = normal_s.length() - 1;

        while (left < right)
        {
            if (normal_s[left] != normal_s[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};