#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int a)
    {
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = find(parent[a]);
    }

    void merge(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        parent[pa] = pb;
    }
};

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        UnionFind uf(n + 1);
        for (vector<int> road : roads)
        {
            uf.merge(road[0], road[1]);
        }
        if (uf.find(1) != uf.find(n))
        {
            return -1;
        }
        sort(roads.begin(), roads.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[2] < b[2];
             });
        for (vector<int> road : roads)
        {
            if (uf.find(road[0]) == uf.find(1))
            {
                return road[2];
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> roads = {
        {1, 2, 9},
        {2, 3, 6},
        {2, 4, 5},
        {1, 4, 7}};
    cout << sol.minScore(n, roads) << endl;
    return 0;
}