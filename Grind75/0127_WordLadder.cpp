#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int check(string s, vector<string> &wordList)
    {
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == s)
            {
                return i;
            }
        }
        return -1;
    }
    int diff(string a, string b)
    {
        int n = a.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                count++;
            }
        }
        return count;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int pos = check(beginWord, wordList);
        if (-1 == pos)
        {
            wordList.push_back(beginWord);
            pos = wordList.size() - 1;
        }
        // create adj
        int n = wordList.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (1 == diff(wordList[i], wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        visited[pos] = true;
        queue<int> q;
        int level = 0;
        q.push(pos);
        while (!q.empty())
        {
            level++;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                int t = q.front();
                q.pop();
                if (wordList[t] == endWord)
                {
                    return level;
                }
                for (int j = 0; j < adj[t].size(); j++)
                {
                    if (!visited[adj[t][j]])
                    {
                        q.push(adj[t][j]);
                        visited[adj[t][j]] = true;
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<string> wordlist = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength("hit", "cog", wordlist);
    return 0;
}