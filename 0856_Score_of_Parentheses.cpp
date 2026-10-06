#include <string>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int ans = 0;
        int layer = 0;
        
        for (int i = 0; i + 1 < s.length(); ++i) {
            char a = s[i];
            char b = s[i + 1];
            
            // If we find the core "()", add 2^(layer) to the answer
            if (a == '(' && b == ')') {
                ans += (1 << layer);
            }
            
            // Update the nesting layer
            if (a == '(') {
                layer++;
            } else {
                layer--;
            }
        }
        
        return ans;
    }
};