# include <iostream>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundred[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousand[4] = {"", "M", "MM", "MMM"};
        return thousand[(num / 1000)] + hundred[((num % 1000) / 100)] + tens[((num % 100) / 10)] + ones[(num % 10)];
    }
};