# include <iostream>
# include <vector>

using namespace std;

class Solution
{
private:
    bool startsWithVowel(string &word)
    {
        return word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u';
    }
    bool endsWithVowel(string &word)
    {
        return word[word.size() - 1] == 'a' || word[word.size() - 1] == 'e' || word[word.size() - 1] == 'i' || word[word.size() - 1] == 'o' || word[word.size() - 1] == 'u';
    }
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        /*
        Steps:- 
        1. create a vector with intiger type to store the result.
        2. create a vector with char type to store the vowels.
        3. create a vector with intiger type to store the prefix sum of the vowels.
        4. create a vector with intiger type to store the result of the queries.
        */
        vector<int> result;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size(), 0);
        vector<int> queryResult(queries.size(), 0);
        prefixSum[0] = startsWithVowel(words[0])&& endsWithVowel(words[0]) ? 1 : 0;
        for (int i = 1; i < words.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + (startsWithVowel(words[i]) && endsWithVowel(words[i]) ? 1 : 0);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            queryResult[i] = prefixSum[queries[i][1]] - (queries[i][0] > 0 ? prefixSum[queries[i][0] - 1] : 0);
        }
        return queryResult;       
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}