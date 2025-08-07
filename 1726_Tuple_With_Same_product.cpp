# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int product = nums[i] * nums[j];
                ans += 8 * mp[product];
                mp[product]++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}