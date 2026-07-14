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

    bool check(int a, int b)
    {
        return find(a) == find(b);
    }
};

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        UnionFind uf(n);
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff)
            {
                uf.merge(i, i + 1);
            }
        }
        vector<bool> result;
        for (vector<int> query : queries)
        {
            result.push_back(uf.check(query[0], query[1]));
        }
        return result;
    }
};

int main()
{
    Solution sol;
    return 0;
}