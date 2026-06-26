#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    vector<Trie *> children;
    bool hasEnd;
    Trie()
    {
        children = vector<Trie *>(10, nullptr);
        hasEnd = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (nullptr == node->children[c - '0'])
            {
                node->children[c - '0'] = new Trie();
            }
            node = node->children[c - '0'];
        }
        node->hasEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (nullptr == node->children[c - '0'])
            {
                return false;
            }
            node = node->children[c - '0'];
        }
        return nullptr != node && node->hasEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            if (nullptr == node->children[c - '0'])
            {
                return false;
            }
            node = node->children[c - '0'];
        }
        return nullptr != node;
    }
};

class Solution
{
private:
    int findPrefix(Trie *t1, Trie *t2)
    {
        int result = 0;
        for (int i = 0; i < 10; i++)
        {
            if (nullptr == t1->children[i] || nullptr == t2->children[i])
            {
                continue;
            }
            // both have this child so we can proceede
            result = max(result, 1 + findPrefix(t1->children[i], t2->children[i]));
        }
        return result;
    }

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        Trie *t1 = new Trie();
        Trie *t2 = new Trie();
        for (int x : arr1)
        {
            t1->insert(to_string(x));
        }
        for (int x : arr2)
        {
            t2->insert(to_string(x));
        }
        return findPrefix(t1, t2);
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {10, 100, 1000, 10000};
    vector<int> arr2 = {1000};
    cout << sol.longestCommonPrefix(arr1, arr2) << endl;
    return 0;
}