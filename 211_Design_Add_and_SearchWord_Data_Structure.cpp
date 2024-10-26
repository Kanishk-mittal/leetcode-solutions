# include <iostream>
# include <vector>

using namespace std;

class WordDictionary
{
private:
    WordDictionary* children[26];
    bool isEndOfWord;
public:
    WordDictionary()
    {
        for (int i = 0; i < 26; ++i)
        {
            this->children[i] = nullptr;
        }
        isEndOfWord = false;
    }

    void addWord(string word)
    {
        WordDictionary* node = this;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new WordDictionary();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word)
    {
        char first = word[0];
        if (first == '.')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (this->children[i] != nullptr)
                {
                    if (word.size() == 1)
                    {
                        if (this->children[i]->isEndOfWord)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        if (this->children[i]->search(word.substr(1)))
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        else
        {
            int index = first - 'a';
            if (this->children[index] == nullptr)
            {
                return false;
            }
            else
            {
                if (word.size() == 1)
                {
                    return this->children[index]->isEndOfWord;
                }
                else
                {
                    return this->children[index]->search(word.substr(1));
                }
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */