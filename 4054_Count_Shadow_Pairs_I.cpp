#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long shadowPairs(vector<int> &nums)
    {
        stack<pair<int, int>> s; // we will store the number and its count {number,count}
        int n = nums.size();
        long long result = 0;
        int stackSize=0;
        for (int i = 0; i < n; i++)
        {
            if (!s.empty() && s.top().first == nums[i])
            {
                s.top().second++;
                
            }

            else if (s.empty() || nums[i] > s.top().first)
            {
                s.push({nums[i], 1});
                
            }
            else
            {
                // we have encountered a smaller element
                // currently all elements are a shadow pair with all elements present in stack lower than them
                while (!s.empty() && s.top().first > nums[i])
                {
                    long long mul = s.top().second;
                    s.pop();
                    stackSize-=mul;
                    result += stackSize * mul; // the current element is present mul times and all of these can make a shadow pair with elements below them
                }
                if (!s.empty() && s.top().first == nums[i])
                {
                    s.top().second++;
                    
                }
                else
                {
                    s.push({nums[i], 1});
                    
                }
            }
            stackSize++;
        }
        // parse all the remaining element in stack
        while (!s.empty())
        {
            long long mul = s.top().second;
            s.pop();
            stackSize-=mul;
            result += stackSize * mul; // the current element is present mul times and all of these can make a shadow pair with elements below them
        }
        return result;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << sol.shadowPairs(nums) << endl;
    return 0;
}