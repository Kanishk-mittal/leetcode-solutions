# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int minValueIndex(vector<int> &nums)
    {
        int minIndex = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[minIndex])
                minIndex = i;
        }
        return minIndex;
    }
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        for (int i = 0; i < k; i++)
        {
            int minIndex = minValueIndex(nums);
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}