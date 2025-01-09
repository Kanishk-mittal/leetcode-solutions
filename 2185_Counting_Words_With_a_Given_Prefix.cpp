# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    bool is_prefix(string &a, string &b)
    {
        if (a.size() > b.size())
        {
            return false;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (is_prefix(pref, words[i]))
            {
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}