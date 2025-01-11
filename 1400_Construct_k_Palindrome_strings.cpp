# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    int charWithOddFreq(const string &s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        int oddFreq = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 1)
            {
                oddFreq++;
            }
        }
        return oddFreq;
    }
public:
    bool canConstruct(string s, int k)
    {
        if (s.size() < k)
        {
            return false;
        }
        if (s.size() == k)
        {
            return true;
        }
        if (k % s.size() == 0)
        {
            return true;
        }
        if (charWithOddFreq(s) <= k)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}