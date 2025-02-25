# include <iostream>
# include <vector>

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int MOD = 1e9 + 7;
        vector<int> prefix(arr.size() + 1, 0);
        // calculating the prefix array
        for (int i = 1; i <= arr.size(); i++)
        {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        int odd_count = 0, even_count = 0;
        int total = 0;
        if (prefix[1] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
            total++;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            if (prefix[i + 1] % 2 == 0)
            {
                even_count++;
                total = (total + odd_count) % MOD;
            }
            else
            {
                odd_count++;
                total = (total + even_count + 1) % MOD;
            }
        }
        return total;
    }
};

using namespace std;

int main(int argc, char const *argv[])
{
    
    return 0;
}