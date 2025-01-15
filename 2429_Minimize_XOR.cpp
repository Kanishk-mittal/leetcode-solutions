#include <iostream>

using namespace std;

class Solution
{
private:
    int countBits(int num)
    {
        int count = 0;
        while (num)
        {
            count++;
            num &= (num - 1);
        }
        return count;
    }
public:
    int minimizeXor(int num1, int num2)
    {
        int bits1 = countBits(num1);
        int bits2 = countBits(num2);

        int x = num1;
        if (bits1 > bits2)
        {
            while (bits1 > bits2)
            {
                x &= (x - 1);
                bits1--;
            }
        }
        else if (bits1 < bits2)
        {
            while (bits1 < bits2)
            {
                x |= (x + 1);
                bits1++;
            }
        }

        return x;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}