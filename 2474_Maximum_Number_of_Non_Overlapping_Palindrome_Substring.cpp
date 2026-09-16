#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    int solve(string &s, int k, vector<vector<bool>>& isPalindrome, int i, vector<int>& memo) {
        // Base case: Not enough characters left to form a palindrome of length >= k
        if (i + k > s.size()) {
            return 0;
        }
        
        // Return cached result
        if (memo[i] != -1) return memo[i];

        // Option 1: Skip current character
        int result = solve(s, k, isPalindrome, i + 1, memo);

        // Option 2: Pick any valid palindrome of length >= k starting at index i
        for (int j = i + k - 1; j < s.size(); j++) {
            if (isPalindrome[i][j]) {
                result = max(result, 1 + solve(s, k, isPalindrome, j + 1, memo));
            }
        }

        return memo[i] = result;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) isPalindrome[i][i] = true;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                    }
                }
            }
        }

        // 2. 1D Memoization array initialized to -1
        vector<int> memo(n, -1);
        return solve(s, k, isPalindrome, 0, memo);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();