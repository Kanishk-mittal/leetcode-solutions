# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n=nums.size();
        long long good_pairs= 0;
        for (int i = 0; i < n; i++)
        {
            nums[i]= nums[i] - i;
        }
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        // count all where freq >=2
        for (auto &p: freq)
        {
            if(p.second >= 2)
            {
                good_pairs += p.second;
            }
        }
        long long total_pairs = (n*(n-1))/2;
        return total_pairs - good_pairs;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}