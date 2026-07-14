#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getNext(int n)
    {
        if (n == -1 || n % 10 == 9)
        {
            return -1;
        }
        return n * 10 + ((n % 10) + 1);
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> result;
        // we will fix a starting digit
        for (int i = 1; i < 9; i++)
        {
            int curr = i;
            while (curr < low)
            {
                curr = getNext(curr);
                if (curr == -1)
                {
                    break;
                }
            }
            while (curr >= low && curr <= high && curr != -1)
            {
                result.push_back(curr);
                curr = getNext(curr);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.sequentialDigits(1000, 13000);
    for (int i : result)
    {
        cout << i << endl;
    }
    return 0;
}