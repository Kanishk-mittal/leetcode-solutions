# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int size = nums.size();
        if (size<=1)
        {
            return true;
        }
        int flag;
        flag=nums[0]%2;
        for (int i = 1; i < size; i++)
        {
            if (nums[i]%2==flag)
            {
                return false;
            }
            flag=nums[i]%2;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}