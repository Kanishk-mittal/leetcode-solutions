#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtrack(vector<vector<int>> &result, vector<int> &current, vector<int> &candidates, int target, int index)
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

int main()
{
    Solution sol;
    return 0;
}

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/