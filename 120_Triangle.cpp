# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> dp(triangle.size(), 0);
        for (int i = 0; i < triangle.size(); i++)
        {
            dp[i] = triangle[triangle.size()-1][i];
        }
        for (int i = triangle.size()-2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}