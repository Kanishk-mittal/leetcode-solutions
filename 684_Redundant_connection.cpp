# include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> group_no(edges.size() + 1, 0);
        int problem_x = 0;
        int problem_y = 0;
        int max_group_no = 1;
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            if (group_no[x]==0&&group_no[y]==0)
            {
                group_no[x] = max_group_no;
                group_no[y] = max_group_no;
                max_group_no++;
            }
            else if (group_no[x] == 0)
            {
                group_no[x] = group_no[y];
            }
            else if (group_no[y] == 0)
            {
                group_no[y] = group_no[x];
            }
            else if (group_no[x] == group_no[y])
            {
                problem_x = x;
                problem_y = y;
                break;
            } 
            else
            {
                int group_x = group_no[x];
                int group_y = group_no[y];
                for (int j = 0; j < group_no.size(); j++)
                {
                    if (group_no[j] == group_y)
                    {
                        group_no[j] = group_x;
                    }
                }
            }           
        }
        return {problem_x, problem_y};
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}