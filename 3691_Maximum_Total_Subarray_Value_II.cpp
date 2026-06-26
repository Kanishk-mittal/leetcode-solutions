#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MaxSegementTree
{
private:
    vector<int> tree;

public:
    MaxSegementTree(vector<int> &nums)
    {
        int n = nums.size();
        tree.resize(n * 2);
        for (int i = 0; i < n; i++)
        {
            tree[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    int getMax(int l, int r)
    {
        int n = tree.size() / 2;
        l += n;
        r += n;
        int res = INT_MIN; // Safer fallback than 0
        while (l <= r)
        {
            if (l % 2 == 1)
                res = max(res, tree[l++]);
            if (r % 2 == 0)
                res = max(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

class MinSegementTree
{
private:
    vector<int> tree;

public:
    MinSegementTree(vector<int> &nums)
    {
        int n = nums.size();
        tree.resize(n * 2);
        for (int i = 0; i < n; i++)
        {
            tree[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    int getMin(int l, int r)
    {
        int n = tree.size() / 2;
        l += n;
        r += n;
        int res = INT_MAX;
        while (l <= r)
        {
            if (l % 2 == 1)
                res = min(res, tree[l++]);
            if (r % 2 == 0)
                res = min(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        MaxSegementTree maxTree(nums);
        MinSegementTree minTree(nums);
        long long res = 0;
        priority_queue<tuple<long long, int, int>> pq; //{value left right}

        // 1. Prime the PQ with the absolute best subarray for every left index
        for (int i = 0; i < n; i++)
        {
            long long value = maxTree.getMax(i, n - 1) - minTree.getMin(i, n - 1);
            pq.push({value, i, n - 1});
        }

        // 2. Greedily pick the top k, replacing each with its immediate smaller counterpart
        while (k-- && !pq.empty())
        {
            auto [value, left, right] = pq.top();
            pq.pop();
            res += value;

            // If we can still shrink the array from the right without crossing bounds
            if (left < right)
            {
                long long nextValue = maxTree.getMax(left, right - 1) - minTree.getMin(left, right - 1);
                pq.push({nextValue, left, right - 1});
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    return 0;
}