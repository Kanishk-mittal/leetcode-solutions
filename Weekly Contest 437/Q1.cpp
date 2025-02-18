# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    bool hasSpecialSubstring(string s, int k)
    {
        if (s.size() < k)
        {
            return false;
        }

        for (int i = 0; i <= s.size() - k; ++i)
        {
            bool isSpecial = true;
            for (int j = 1; j < k; ++j)
            {
                if (s[i + j] != s[i])
                {
                    isSpecial = false;
                    break;
                }
            }

            if (isSpecial)
            {
                if ((i > 0 && s[i - 1] == s[i]) || (i + k < s.size() && s[i + k] == s[i]))
                {
                    continue;
                }
                return true;
            }
        }

        return false;
    }
};

    int
    main(int argc, char const *argv[])
{
    
    return 0;
}