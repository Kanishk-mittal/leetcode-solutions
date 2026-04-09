#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        vector<char> c(s.begin(), s.end());
        int n = c.size();
        int cur_a = 0, cur_b = 0, cur_c = 0;
        int max_a = 0, max_b = 0, max_c = 0;

        for (int i = 0; i < n; i++)
        {
            if (c[i] == 'a')
            {
                cur_a = (i > 0 && c[i - 1] == 'a') ? cur_a + 1 : 1;
                max_a = max(max_a, cur_a);
            }
            else if (c[i] == 'b')
            {
                cur_b = (i > 0 && c[i - 1] == 'b') ? cur_b + 1 : 1;
                max_b = max(max_b, cur_b);
            }
            else
            {
                cur_c = (i > 0 && c[i - 1] == 'c') ? cur_c + 1 : 1;
                max_c = max(max_c, cur_c);
            }
        }

        int res = max({max_a, max_b, max_c});
        res = max(res, find2(c, 'a', 'b'));
        res = max(res, find2(c, 'a', 'c'));
        res = max(res, find2(c, 'b', 'c'));
        res = max(res, find3(c));
        return res;
    }

private:
    int find2(const vector<char> &c, char x, char y)
    {
        int n = c.size(), max_len = 0;
        vector<int> first(2 * n + 1, -2);
        int clear_idx = -1, diff = n;
        first[diff] = -1;
        for (int i = 0; i < n; i++)
        {
            if (c[i] != x && c[i] != y)
            {
                clear_idx = i;
                diff = n;
                first[diff] = clear_idx;
            }
            else
            {
                if (c[i] == x)
                    diff++;
                else
                    diff--;
                if (first[diff] < clear_idx)
                {
                    first[diff] = i;
                }
                else
                {
                    max_len = max(max_len, i - first[diff]);
                }
            }
        }
        return max_len;
    }

    int find3(const vector<char> &c)
    {
        long long state = LLONG_MAX / 2;
        unordered_map<long long, int> first;
        first[state] = -1;
        int max_len = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == 'a')
                state += 1000001LL;
            else if (c[i] == 'b')
                state -= 1000000LL;
            else
                state--;
            if (first.count(state))
            {
                max_len = max(max_len, i - first[state]);
            }
            else
            {
                first[state] = i;
            }
        }
        return max_len;
    }
};

int main()
{
    Solution sol;
    string s = "abcabc";
    cout << sol.longestBalanced(s) << endl;
    return 0;
}