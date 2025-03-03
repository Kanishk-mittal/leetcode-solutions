# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n =nums.size();
        vector<int> result(n,0);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] < pivot)
            {
                result[curr++] = nums[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i]==pivot)
            {
                result[curr++] = nums[i];
            }            
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i]>pivot)
            {
                result[curr++] = nums[i];
            }            
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}