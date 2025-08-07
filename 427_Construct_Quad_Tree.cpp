#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
private:
    Node *helper(vector<vector<int>> &grid, int x, int y, int size)
    {
        if (size == 1)
        {
            return new Node(grid[x][y] == 1, true);
        }
        Node *topLeft = helper(grid, x, y, size / 2);
        Node *topRight = helper(grid, x, y + size / 2, size / 2);
        Node *bottomLeft = helper(grid, x + size / 2, y, size / 2);
        Node *bottomRight = helper(grid, x + size / 2, y + size / 2, size / 2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            return new Node(topLeft->val, true);
        }
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return nullptr;
        }
        
        return helper(grid, 0, 0, grid.size());
    }
};