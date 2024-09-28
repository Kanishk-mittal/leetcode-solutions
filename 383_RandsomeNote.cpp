# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magazinefreq;
        for (char c : magazine)
        {
            magazinefreq[c]++;
        }
        for (char c : ransomNote)
        {
            if (magazinefreq.find(c) == magazinefreq.end() || magazinefreq[c] == 0)
            {
                return false;
            }
            magazinefreq[c]--;
        }
        return true;
    }
};