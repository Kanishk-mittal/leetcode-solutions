# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int n = digits.size();
        for (int i = n-1; i >=0; i--)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if (carry == 0)
            {
                return digits;
            }            
        }
        if (carry!=0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}