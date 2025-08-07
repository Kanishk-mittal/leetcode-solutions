# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int index)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                current.push_back(candidates[i]);
                backtrack(result, current, candidates, target - candidates[i], i);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, candidates, target, 0);
        return result;
    }
};