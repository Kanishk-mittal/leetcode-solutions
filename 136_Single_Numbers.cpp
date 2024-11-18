# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        return result;  
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}