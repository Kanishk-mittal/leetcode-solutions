#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<vector<int>>> &memo, vector<vector<int>> &count, int i, int m, int n)
    {
        // here i is the index for whihc we have to make decision whether to include or not
        // m is the remaining number of 0 we can have
        // n is the remaining number of 1 we can have
        // count is a vecotr where the inner vector is of size 2
        // count[i][0] -> no of 0 in i'th string
        // count[i][1] -> no of 1 in i'th string

        // here is the base case
        //  if either of m or n goes negative return -1
        if (m < 0 || n < 0)
        {
            return -1;
        }
        // now the condition for i if it is greater than or equal to count.size() it means we have traversed the entire array
        // here return 0
        if (i == count.size())
        {
            return 0;
        }

        // before processing lets check whether we already know the answer or not
        if (memo[m][n][i] != -2)
        {
            return memo[m][n][i];
        }

        // at this point we hav two coices to either choose i or reject i
        int accept = dfs(memo, count, i + 1, m - count[i][0], n - count[i][1]);
        int reject = dfs(memo, count, i + 1, m, n);
        // add 1 if accepting is a valid option
        if (accept != -1)
        {
            accept++;
        }
        // also update the memo
        memo[m][n][i] = max(accept, reject);
        return max(accept, reject);
    }
    vector<int> countFunc(string str)
    {
        vector<int> result(2, 0);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
            {
                result[1]++;
            }
            else
            {
                result[0]++;
            }
        }
        return result;
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // first we have to make the pairs vector
        vector<vector<int>> count;
        vector<vector<vector<int>>> memo(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size() + 1, -2))); //-2 denote that this state is not parsed yet
        count.reserve(strs.size());
        for (int i = 0; i < strs.size(); i++)
        {
            count.push_back(countFunc(strs[i]));
        }
        // now just return the output of dfs
        return dfs(memo, count, 0, m, n);
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    int result = sol.findMaxForm(strs, m, n);
    return 0;
}