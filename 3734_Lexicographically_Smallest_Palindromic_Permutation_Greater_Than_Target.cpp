#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string lexPalindromicPermutation(string s, string target)
    {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s)
        {
            count[c - 'a']++;
        }

        int oddCount = 0;
        char oddChar = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2 != 0)
            {
                oddCount++;
                oddChar = 'a' + i;
            }
            count[i] /= 2;
        }

        if (oddCount > 1)
        {
            return "";
        }

        int half = n / 2;
        string target_half = target.substr(0, half);

        // Find the maximum prefix of target_half we can exactly form
        int L = 0;
        vector<int> tempCount = count;
        while (L < half && tempCount[target_half[L] - 'a'] > 0)
        {
            tempCount[target_half[L] - 'a']--;
            L++;
        }

        // Case 1: Check if forming the exact first half creates a valid greater palindrome
        if (L == half)
        {
            string full = target_half;
            if (n % 2 != 0)
                full.push_back(oddChar);
            string back = target_half;
            reverse(back.begin(), back.end());
            full += back;

            if (full > target)
            {
                return full;
            }
        }

        // Case 2: Find the latest possible index to diverge and place a strictly greater character
        int max_i = min(half - 1, L);
        for (int i = max_i; i >= 0; i--)
        {
            vector<int> rem = count;
            for (int j = 0; j < i; j++)
            {
                rem[target_half[j] - 'a']--;
            }

            char best_c = 0;
            // Find the smallest available character greater than target_half[i]
            for (int c = target_half[i] - 'a' + 1; c < 26; c++)
            {
                if (rem[c] > 0)
                {
                    best_c = 'a' + c;
                    rem[c]--;
                    break;
                }
            }

            // Lock in the divergence character and greedily append the remainder alphabetically
            if (best_c != 0)
            {
                string leftHalf = target_half.substr(0, i);
                leftHalf.push_back(best_c);

                for (int c = 0; c < 26; c++)
                {
                    while (rem[c] > 0)
                    {
                        leftHalf.push_back('a' + c);
                        rem[c]--;
                    }
                }

                string res = leftHalf;
                if (n % 2 != 0)
                    res.push_back(oddChar);
                string back = leftHalf;
                reverse(back.begin(), back.end());
                res += back;

                return res;
            }
        }

        return "";
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();