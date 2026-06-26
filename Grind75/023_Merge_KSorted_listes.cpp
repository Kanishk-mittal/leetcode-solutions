#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // first lets make a priority queue
        auto cmp = [](ListNode *a, ListNode *b)
        { return a->val < b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (ListNode *node : lists)
        {
            if (nullptr != node)
            {
                pq.push(node);
            }
        }
        ListNode *dummy(0);
        ListNode *curr = dummy;
        while (!pq.empty())
        {
            curr->next = pq.top();
            curr = curr->next;
            pq.pop();
            if (nullptr != curr->next)
            {
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};

int main()
{
    Solution sol;
    return 0;
}