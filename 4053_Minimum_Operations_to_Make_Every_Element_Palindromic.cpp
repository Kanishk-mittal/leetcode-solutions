#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long count = 0;
        
        for (long long curr : nums) {
            if (curr < 10) {
                continue; // Single digits are already palindromes
            }

            if (curr % 2 == 0) {
                auto it = upper_bound(evenPalindrome.begin(), evenPalindrome.end(), curr);
                long long ub = distance(evenPalindrome.begin(), it);
                
                if (ub == 0) {
                    count += (evenPalindrome[ub] - curr) / 2;
                } else if (ub == evenPalindrome.size()) {
                    count += (curr - evenPalindrome[ub - 1]) / 2;
                } else {
                    count += min(curr - evenPalindrome[ub - 1], evenPalindrome[ub] - curr) / 2;
                }
            } else {
                auto it = upper_bound(oddPalindrome.begin(), oddPalindrome.end(), curr);
                long long ub = distance(oddPalindrome.begin(), it);
                
                if (ub == 0) {
                    count += (oddPalindrome[ub] - curr) / 2;
                } else if (ub == oddPalindrome.size()) {
                    count += (curr - oddPalindrome[ub - 1]) / 2;
                } else {
                    count += min(curr - oddPalindrome[ub - 1], oddPalindrome[ub] - curr) / 2;
                }
            }
        }
        return count;
    }
};

// 1. Declare these globally so they persist across all test cases
vector<long long> oddPalindrome;
vector<long long> evenPalindrome;

// 2. Use an Immediately Invoked Lambda to precompute everything exactly ONCE.
int init = []() {
    // Fast I/O to prevent TLE on reading large arrays
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    oddPalindrome = {1, 3, 5, 7, 9};
    evenPalindrome = {0, 2, 4, 6, 8};
    
    // Go up to 99999 to guarantee we generate palindromes > 10^9
    for (int i = 1; i <= 10000; i++) {
        int temp = i;
        long long rev = 0;
        long long mult_even = 1;
        
        // Inline math to find reverse and the power of 10 multiplier simultaneously
        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
            mult_even *= 10;
        }
        
        // Generate Even-length palindrome (e.g., 12 -> 1221)
        long long p1 = (i * mult_even) + rev;
        if (p1 % 2 == 0) evenPalindrome.push_back(p1);
        else oddPalindrome.push_back(p1);
        
        // Generate Odd-length palindromes (e.g., 12 -> 12_21)
        long long mult_odd_i = mult_even * 10;
        for (int j = 0; j < 10; j++) {
            long long p2 = (i * mult_odd_i) + (j * mult_even) + rev;
            if (p2 % 2 == 0) evenPalindrome.push_back(p2);
            else oddPalindrome.push_back(p2);
        }
    }
    
    sort(evenPalindrome.begin(), evenPalindrome.end());
    sort(oddPalindrome.begin(), oddPalindrome.end());
    
    return 0;
}();