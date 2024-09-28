#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to handle edge cases like removing the head node
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;

        // Move the first pointer n+1 steps ahead, to maintain a gap of n nodes
        for (int i = 0; i <= n; i++)
        {
            first = first->next;
        }

        // Move both pointers until the first reaches the end
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        ListNode *nodeToRemove = second->next;
        second->next = second->next->next;
        delete nodeToRemove;

        // Return the new head
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};