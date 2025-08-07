# include <iostream>
# include <vector>

using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> char_freq(26, 0);
        for (char ch : s)
            char_freq[ch - 'a']++;
        int reduced = 0;
        for (int i = 0; i < char_freq.size(); i++)
        {
            if (char_freq[i]>=3)
            {
                if (char_freq[i] % 2 == 1)
                    reduced += char_freq[i] - 1;
                else
                    reduced += char_freq[i] - 2;
            }
        }
        return s.size() - reduced;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    cout << obj.minimumLength("aa") << endl;
    return 0;
}