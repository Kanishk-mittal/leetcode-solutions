# include <iostream>
# include <vector>

using namespace std;

class Trie
{
private:
    Trie* children[26];
    bool isEndOfWord;
public:
    Trie()
    {
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }

    void insert(string word)
    {
        Trie* node = this;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word)
    {
        Trie* node = this;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        Trie* node = this;
        for (auto ch : prefix)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[])
{
    cout << "Implement Trie (Prefix Tree)" << endl;
    return 0;
}
