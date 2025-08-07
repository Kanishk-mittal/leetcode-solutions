# include <iostream>
# include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string common_prefix = strs[0];
        int prefix_length = strs[0].size();
        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = 0; j < prefix_length; j++)
            {
                if (strs[i][j] != common_prefix[j])
                {
                    prefix_length = j;
                    break;
                }
            }
        }
        return common_prefix.substr(0, prefix_length);
    }
};