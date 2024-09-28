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
private:
    int count(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        int len = count(head);
        k = k % len;
        if (k == 0)
            return head;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = head;
        for (int i = 0; i < len - k - 1; i++)
        {
            head = head->next;
        }
        ListNode *newHead = head->next;
        head->next = nullptr;
        return newHead;
    }
};