# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution
{
private:
    vector<int> getCharFreq(const string &word)
    {
        vector<int> freq(26, 0);
        for (char c : word)
        {
            freq[c - 'a']++;
        }
        return freq;
    }

public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        // Calculate the maximum frequency for each character in words2
        vector<int> maxFreq(26, 0);
        for (const string &word : words2)
        {
            vector<int> freq = getCharFreq(word);
            for (int i = 0; i < 26; i++)
            {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Check if each word in words1 is a universal word
        vector<string> res;
        for (const string &word : words1)
        {
            vector<int> freq = getCharFreq(word);
            bool isSubset = true;
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] < maxFreq[i])
                {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
            {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}