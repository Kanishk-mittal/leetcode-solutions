#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head; // No need to reverse if left == right

        ListNode *prev = nullptr, *cur = head;

        // Move `cur` to the `left-th` node and `prev` to the node before `left`
        for (int i = 1; i < left; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        // `prev` points to the node before `left`, `cur` is at the `left-th` node
        ListNode *con = prev, *tail = cur;

        // Reverse the sublist between `left` and `right`
        ListNode *next = nullptr;
        for (int i = 0; i < right - left + 1; i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // Fix the connections:
        if (con != nullptr)
        {
            con->next = prev; // Connect node before `left` to the new `left-th` node
        }
        else
        {
            head = prev; // If `left` is 1, update the head
        }

        tail->next = cur; // Connect the `right-th` node to the rest of the list

        return head;
    }
};