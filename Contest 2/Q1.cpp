# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(prefix[i]-(prefix[nums.size()-1]-prefix[i]))%2==0)
            {
                count++;
            }
        }
        if (count!=0)
        {
            count--;
        }
        return count;
    }
};

    int
    main(int argc, char const *argv[])
{
    
    return 0;
}