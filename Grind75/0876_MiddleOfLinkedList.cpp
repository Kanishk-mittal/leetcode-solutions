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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (nullptr != fast && nullptr != fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    Solution sol;
    return 0;
}