#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> mp;
        queue<Node *> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            for (Node *neighbor : curr->neighbors)
            {
                if (mp.find(neighbor) == mp.end())
                {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }
        return mp[node];
    }
};

int main()
{
    Solution sol;
    return 0;
}