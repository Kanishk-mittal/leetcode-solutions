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
    ListNode *deleteMiddle(ListNode *head)
    {
        // 1. Handle edge cases: Empty list or list with only one node
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *slow = head;
        // 2. Give 'fast' a head start so 'slow' stops one step before the middle
        ListNode *fast = head->next->next;

        // 3. Traverse the list
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 4. Delete the middle node by bypassing it
        slow->next = slow->next->next;

        return head;
    }
};

int main()
{
    Solution sol;
    return 0;
}