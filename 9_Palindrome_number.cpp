# include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long long reversed = 0;
        int original = x;
        while (x > 0)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return reversed == original;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}