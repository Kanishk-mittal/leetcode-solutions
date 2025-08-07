# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        string word;
        for (char c : s)
        {
            if (c == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += c;
            }
        }
        words.push_back(word);
        if (pattern.size() != words.size())
        {
            return false;
        }
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        for (int i = 0; i < pattern.size(); i++)
        {
            char p = pattern[i];
            string w = words[i];
            if (p2s.count(p) && p2s[p] != w)
            {
                return false;
            }
            if (s2p.count(w) && s2p[w] != p)
            {
                return false;
            }
            p2s[p] = w;
            s2p[w] = p;
        }
        return true;
    }
};