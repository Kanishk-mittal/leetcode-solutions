#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int n : nums)
        {
            if (s.find(n) != s.end())
            {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    return 0;
}