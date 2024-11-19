# include <iostream>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (left<right)
        {
            right &= right - 1;
        }
        return right;        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}

/*
1000000000000000000000000001000
1111111111111111111111111111111
1000000000000000000000000000000
*/