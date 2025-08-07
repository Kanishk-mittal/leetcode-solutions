#include <iostream>
#include <vector>
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int curr = nums[0];   
        int u = 0;            
        std::vector<int> rem; 
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == curr)
            {
                rem.push_back(nums[i]); 
            }
            else
            {
                curr = nums[i]; 
                u++;            
            }
        }
        for (int j : rem)
        {
            nums.erase(std::remove(nums.begin(), nums.end(), j), nums.end());
        }
        return u; 
    }
};
