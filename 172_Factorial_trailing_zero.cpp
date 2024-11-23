# include <iostream>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    cout<<Solution().trailingZeroes(30)<<endl;
    return 0;
}