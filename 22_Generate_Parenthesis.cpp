# include <iostream>
# include <vector>
# include <set>
# include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        set<string> result;
        if (n == 0)
        {
            result.insert("");
        }
        else
        {
            vector<string> prev = generateParenthesis(n - 1);
            for (string str : prev)
            {
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] == '(')
                    {
                        str.insert(str.begin() + i + 1, '(');
                        str.insert(str.begin() + i + 2, ')');
                        result.insert(str);
                        str.erase(str.begin() + i + 1, str.begin() + i + 3);
                    }
                }
                result.insert("()" + str);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};