#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
private:
    long long int factorial(int n)
    {
        long long int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
        return fact;
    }

    long long int nCr(int n, int r)
    {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
public:
    int minMaxSums(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long int sum = 0;  
        const long long int mod = pow(10, 9) + 7;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        for (int i = 2; i < k; i++)
        {
            long long int layer_sum = 0;
            for (int j = 0; j < n; j++)
            {
                long long countri_of_aj_as_min = nums[j]*nCr(n-j,i);
                long long countri_of_aj_as_max = nums[j]*nCr(j+1,i);
                layer_sum += countri_of_aj_as_min + countri_of_aj_as_max;
                layer_sum = layer_sum % mod;
            }
            sum += layer_sum;
            sum = sum % mod;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    Solution obj;
    cout << obj.minMaxSums(nums, k) << endl;
    return 0;
}