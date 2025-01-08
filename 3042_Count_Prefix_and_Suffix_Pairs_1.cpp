# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    bool isPrefixSuffix(string &a, string &b)
    {
        // this returns true if a is a prefix of b and a is a suffix of b
        if (a.size() > b.size())
        {
            return false;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i] || a[i] != b[b.size() - a.size() + i])
            {
                return false;
            }
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (isPrefixSuffix(words[i], words[j]))
                {
                    res++;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> words = {"abab","ab"};
    cout << sol.countPrefixSuffixPairs(words) << endl;
    return 0;
}