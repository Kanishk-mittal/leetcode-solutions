# include <vector>
# include <iostream>
# include <map>
# include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> anagram_map;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            anagram_map[temp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto groups : anagram_map)
        {
            result.push_back(groups.second);
        }
        return result;
    }
};