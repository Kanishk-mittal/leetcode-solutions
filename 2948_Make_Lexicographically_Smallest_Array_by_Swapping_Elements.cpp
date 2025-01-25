# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int left=0, right=1;
        while (right < arr.size())
        {
            while (right < arr.size() && abs(arr[right].first - arr[right - 1].first) <= limit)
            {
                right++;
            }
            // now our first group is from left to right-1
            vector<int> indexes(right-left);
            for (int i = left; i < right; i++)
            {
                indexes[i-left] = arr[i].second;
            }
            sort(indexes.begin(), indexes.end());
            for (int i = 0; i < indexes.size(); i++)
            {
                nums[indexes[i]] = arr[left+i].first;
            }
            left = right;
            right++;
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}