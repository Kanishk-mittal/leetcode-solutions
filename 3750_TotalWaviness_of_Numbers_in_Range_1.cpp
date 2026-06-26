#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int waviness(int num)
    {
        if (num <= 99)
        {
            return 0;
        }
        int result = 0;
        int n = log10(num) + 1;
        for (int i = 1; i < n - 1; i++)
        {
            int right = (num % (int)pow(10, i)) / (int)pow(10, i - 1);
            int curr = (num % (int)pow(10, i + 1)) / (int)pow(10, i);
            int left = (num % (int)pow(10, i + 2)) / (int)pow(10, i + 1);
            if (curr < left && curr < right)
            {
                result++;
            }
            if (curr > left && curr > right)
            {
                result++;
            }
        }
        return result;
    }

public:
    int totalWaviness(int num1, int num2)
    {
        int result = 0;
        for (int i = num1; i <= num2; i++)
        {
            result += waviness(i);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.totalWaviness(120, 130) << endl;
    return 0;
}