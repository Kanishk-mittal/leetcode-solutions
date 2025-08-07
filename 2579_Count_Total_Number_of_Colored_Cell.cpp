# include <iostream>

using namespace std;

class Solution
{
public:
    long long coloredCells(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 5;
        }
        else
        {
            long long sum = 0;
            int k = (2 * n) - 3;
            while (k >= 1)
            {
                sum += k;
                k -= 2;
            }
            sum = sum * 2;
            sum += (2 * n) - 1;
            return sum;
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}