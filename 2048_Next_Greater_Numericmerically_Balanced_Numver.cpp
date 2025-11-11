#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool isBalanced(int num)
    {
        vector<int> freq(10, 0);
        while (num > 0)
        {
            freq[num % 10]++;
            num /= 10;
        }
        for (int i = 0; i < 10; i++)
        {
            if (freq[i] > 0 && freq[i] != i)
            {
                return false;
            }
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n)
    {
        for (int i = n + 1; i < 1224444; i++)
        {
            if (isBalanced(i))
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    cout << sol.nextBeautifulNumber(n) << endl;
    return 0;
}