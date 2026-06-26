#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        vector<int> locked(26, 0);
        int count = 0;
        for (char c : tasks)
        {
            freq[c - 'A']++;
            count++;
        }
        int cycle = 0;
        while (count > 0)
        {
            int idx = -1;
            int m = 1;
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] >= m && locked[i] <= cycle)
                {
                    idx = i;
                }
            }
            if (-1 != idx)
            {
                count--;
                freq[idx]--;
                locked[idx] += (n + 1);
            }
            cycle++;
        }
        cout << endl;
        return cycle;
    }
};

int main()
{
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 3;
    cout << sol.leastInterval(tasks, n);
    return 0;
}