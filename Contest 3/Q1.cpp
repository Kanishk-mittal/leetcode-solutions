#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        int max_odd = 0;
        int min_even = INT_MAX;

        for (auto &entry : freq)
        {
            if (entry.second % 2 != 0)
            {
                max_odd = max(max_odd, entry.second);
            }
            else
            {
                min_even = min(min_even, entry.second);
            }
        }

        return max_odd - min_even;
    }
};

int main()
{
    Solution sol;
    string s1 = "aaaaabbc";
    cout << sol.maxDifference(s1) << endl; // Output: 3

    string s2 = "abcabcab";
    cout << sol.maxDifference(s2) << endl; // Output: 1

    string s3 = "txt";
    cout << sol.maxDifference(s3) << endl; // Output: -1

    return 0;
}
