#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * This represents a node in our segment tree.
 */
class Node
{
public:
    int pref;   // length of repeating character from LHS
    int suf;    // length of repeating character from RHS
    int best;   // best answer for current node
    char lChar; // character at the leftmost side
    char rChar; // character at the rightmost side
    int len;    // length of this node

    /**
     * @brief Constructs a segment-tree node storing prefix/suffix lengths,
     *        the best streak length, boundary characters, and node length.
     *
     * @param pref Length of the repeating character run from the left side.
     * @param suf Length of the repeating character run from the right side.
     * @param best Maximum repeating run length present in this node.
     * @param lChar Leftmost character in the node.
     * @param rChar Rightmost character in the node.
     * @param len Number of characters covered by this node.
     */
    Node(int pref, int suf, int best, char lChar, char rChar, int len)
    {
        this->pref = pref;
        this->suf = suf;
        this->best = best;
        this->lChar = lChar;
        this->rChar = rChar;
        this->len = len;
    }

    /**
     * @brief Default constructor for empty/dummy nodes.
     */
    Node()
    {
        this->pref = 0;
        this->suf = 0;
        this->best = 0;
        this->lChar = '#'; // Use a dummy character that won't match a-z
        this->rChar = '#';
        this->len = 0;
    }
};

/**
 * @brief Merges two nodes of the segment tree.
 *
 * @param left Left node (passed by constant reference to avoid copying).
 * @param right Right node (passed by constant reference).
 * @return Merged node.
 */
Node merge(const Node &left, const Node &right)
{
    // If one of the nodes is completely empty (dummy padding), return the other
    if (left.len == 0)
        return right;
    if (right.len == 0)
        return left;

    Node result;

    // left and right character of new node
    result.lChar = left.lChar;
    result.rChar = right.rChar;
    result.len = left.len + right.len;

    // prefix of new node
    if ((left.pref == left.len) && (left.rChar == right.lChar))
    {
        // case when the prefix covers the entire left node
        result.pref = left.len + right.pref;
    }
    else
    {
        // in all other cases we have to use the left prefix
        result.pref = left.pref;
    }

    // suffix of new node
    if ((right.suf == right.len) && (left.rChar == right.lChar))
    {
        // case when the suffix covers the entire right node
        result.suf = right.len + left.suf;
    }
    else
    {
        // in all other cases we have to use the right suffix
        result.suf = right.suf;
    }

    // best answer
    result.best = max(left.best, right.best);

    // if there is a better one in the middle spanning across both nodes
    if (left.rChar == right.lChar)
    {
        result.best = max(result.best, (left.suf + right.pref));
    }

    return result;
}

class SegmentTree
{
private:
    vector<Node> tree; // Storing actual objects, avoiding 'new' and memory leaks
    int n;             // Padded size (must be a power of 2)

public:
    SegmentTree(string s)
    {
        int originalSize = s.size();

        // Pad n to the next power of 2 for the iterative tree to work correctly
        n = 1;
        while (n < originalSize)
        {
            n *= 2;
        }

        tree.resize(n * 2);

        // Initialize leaves with actual string characters
        for (int i = 0; i < originalSize; i++)
        {
            tree[n + i] = Node(1, 1, 1, s[i], s[i], 1);
        }

        // Initialize remaining padding leaves with dummy values
        for (int i = originalSize; i < n; i++)
        {
            tree[n + i] = Node(0, 0, 0, '#', '#', 0);
        }

        // Build the tree bottom-up
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    int query()
    {
        return tree[1].best;
    }

    void update(int idx, char c)
    {
        int curr = n + idx;
        tree[curr] = Node(1, 1, 1, c, c, 1);

        // updating all parents
        int parent = curr / 2;
        while (parent > 0)
        {
            tree[parent] = merge(tree[parent * 2], tree[parent * 2 + 1]);
            parent /= 2;
        }
    }
};

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        SegmentTree segTree(s);
        int q = queryCharacters.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++)
        {
            segTree.update(queryIndices[i], queryCharacters[i]);
            result[i] = segTree.query();
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "babacc";
    string queryCharacters = "bcb";
    vector<int> queryIndexes = {1, 3, 3};
    vector<int> result = sol.longestRepeating(s, queryCharacters, queryIndexes);
    for (int i : result)
    {
        cout << i << endl;
    }
    return 0;
}
