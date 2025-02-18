# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    bool isSpecial(string &s, int left, int right, vector<int> &outerFreq)
    {
        vector<int> freq(26, 0);
        for (int i = left; i <= right; i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (!(freq[i] ==0|| freq[i]==outerFreq[i]))
            {
                return false;
            }
        }
        return true;
    }
public:
    bool maxSubstringLength(string s, int k)
    {
        vector<int> count(26, 0);
        int specialCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }
        int left = 0;
        for (int i = 1; i < s.size(); i++)
        {
            int right = i;
            if (isSpecial(s, left, right, count))
            {
                specialCount++;
                left = right;
            }
        }
        return specialCount>=k;
    }
};

    int
    main(int argc, char const *argv[])
{
    Solution obj;
    string s = "abcdbaefab";
    int k = 2;
    cout << obj.maxSubstringLength(s, k) << endl;
    return 0;
}