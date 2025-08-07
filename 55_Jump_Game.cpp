#include <iostream>
#include <vector>

using namespace std;

bool canJump(int *nums, int numsSize)
{
    int gas = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (gas < 0)
        {
            return false;
        }
        else if (nums[i] > gas)
        {
            gas = nums[i];
        }
        gas = gas - 1;
    }
    return true;
}