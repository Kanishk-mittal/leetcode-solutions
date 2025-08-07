# include <iostream>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        if (x == 1)
        {
            return 1;
        }
        
        int left = 0;
        int right = x;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            long long square = (long long)mid * mid;
            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return right - 1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}