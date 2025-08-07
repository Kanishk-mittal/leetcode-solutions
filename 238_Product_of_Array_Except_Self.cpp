# include <iostream>
# include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 1);
        int forward_product = 1;
        int reverse_product = 1;

        for (int i = 0; i < size; i++)
        {
            answer[i] *= forward_product;
            forward_product *= nums[i];

            answer[size - 1 - i] *= reverse_product;
            reverse_product *= nums[size - 1 - i];
        }

        return answer;
    }
};