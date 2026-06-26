#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool hasEnd;

public:
    Trie()
    {
        children = vector<Trie *>(26, nullptr);
        hasEnd = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (nullptr == node->children[c - 'a'])
            {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->hasEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (nullptr == node->children[c - 'a'])
            {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return nullptr != node && node->hasEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            if (nullptr == node->children[c - 'a'])
            {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return nullptr != node;
    }
};

int main()
{
    Trie sol;
    return 0;
}