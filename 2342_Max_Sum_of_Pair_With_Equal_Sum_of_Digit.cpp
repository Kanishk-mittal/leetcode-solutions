#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int digitSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    pair<int,int> top2(vector<int> &v)
    {
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int n : v)
        {
            if (n > max1)
            {
                max2 = max1;
                max1 = n;
            }
            else if (n > max2)
            {
                max2 = n;
            }
        }
        return {max1, max2};
    }
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> map;
        // creating map of digit sum and the numbers
        for (int n : nums)
        {
            map[digitSum(n)].push_back(n);
        }
        int maxSum = -1;
        // iterating over the map and for the one with more than 1 element calculate sum of two largest elements
        for (auto &p : map)
        {
            vector<int> &v = map[p.first];
            if (v.size() > 1)
            {
                pair<int,int> top = top2(v);
                maxSum = max(maxSum, top.first + top.second);
            }
        }
        return maxSum;        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}