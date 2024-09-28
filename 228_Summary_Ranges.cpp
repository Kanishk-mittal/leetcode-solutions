# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Solution
{
private:
    string make_interval(int begin, int end)
    {
        if (begin == end)
        {
            return to_string(begin);
        }
        else
        {
            return to_string(begin) + "->" + to_string(end);
        }
    }

public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }

        int begin = nums[0];
        int end = nums[0];
        vector<string> interverls;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == (end + 1))
            {
                end += 1;
            }
            else
            {
                interverls.push_back(make_interval(begin, end));
                begin = nums[i];
                end = nums[i];
            }
        }
        interverls.push_back(make_interval(begin, end));
        return interverls;
    }
};