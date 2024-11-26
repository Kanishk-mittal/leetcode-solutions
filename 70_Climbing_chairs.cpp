# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int count_possibility(int n, vector<int> &memo)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (memo[n] != -1)
            return memo[n];
        memo[n] = count_possibility(n-1, memo) + count_possibility(n-2, memo);
        return memo[n];
    }
public:
    int climbStairs(int n)
    {
        vector<int> memo(n+1, -1);
        return count_possibility(n, memo);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}