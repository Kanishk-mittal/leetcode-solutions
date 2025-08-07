# include <iostream>
# include <vector>
using namespace std;

class Solution
{
public:
    int min(int val1, int val2)
    {
        if (val1 < val2)
        {
            return val1;
        }
        return val2;
    }
    int maxArea(vector<int> &height)
    {
        int left;
        int right;
        left = 0;
        right = height.size() - 1;
        int max_vol = 0;
        while (left < right)
        {
            int cur_vol;
            cur_vol = min(height[left], height[right]) * (right - left);
            if (cur_vol > max_vol)
            {
                max_vol = cur_vol;
            }
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_vol;
    }
};