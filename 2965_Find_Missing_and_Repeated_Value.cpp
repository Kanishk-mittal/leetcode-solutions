# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> map(m*n,0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map[grid[i][j]-1]+=1;
            }
        }
        int repeated=0;
        int missing=0;
        for (int i = 0; i < map.size(); i++)
        {
            if(map[i]==0)
            {
                missing=i+1;
            }
            if(map[i]>1)
            {
                repeated=i+1;
            }
        }
        return {repeated,missing};
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}