# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        unordered_map<int, int> mp;
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i][0]] = nums1[i][1];
        }
        for (int j = 0; j < nums2.size(); j++)
        {
            if (mp.find(nums2[j][0]) != mp.end())
            {
                mp[nums2[j][0]] += nums2[j][1];
            }
            else
            {
                mp[nums2[j][0]] = nums2[j][1];
            }
        }
        vector<vector<int>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back({it->first, it->second});
        }
        // sort ans according to the first element
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}