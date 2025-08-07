# include <iostream>
# include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> s_to_t_map;
        unordered_map<char, char> t_to_s_map;

        for (int i = 0; i < s.size(); i++)
        {
            char s_char = s[i];
            char t_char = t[i];

            // Check if there's an existing mapping in s -> t direction
            if (s_to_t_map.find(s_char) != s_to_t_map.end())
            {
                if (s_to_t_map[s_char] != t_char)
                {
                    return false;
                }
            }
            else
            {
                s_to_t_map[s_char] = t_char;
            }

            // Check if there's an existing mapping in t -> s direction
            if (t_to_s_map.find(t_char) != t_to_s_map.end())
            {
                if (t_to_s_map[t_char] != s_char)
                {
                    return false;
                }
            }
            else
            {
                t_to_s_map[t_char] = s_char;
            }
        }

        return true;
    }
};