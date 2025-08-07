# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] == 1)
            {
                continue;
            }
            else
            {
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0 ? 1 : 0;
                nums[i+2] = nums[i+2] == 0 ? 1 : 0;
                count++;
            }
        }
        if (nums[nums.size()-2] == 0)
        {
            return -1;
        }
        if (nums[nums.size()-1] == 0)
        {
            return -1;
        }
        return count;        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}