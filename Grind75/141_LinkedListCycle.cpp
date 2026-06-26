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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (nullptr != fast && nullptr != fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
// class Solution
// {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         set<ListNode *> s;
//         while (head != nullptr)
//         {
//             if (s.find(head) != s.end())
//             {
//                 return true;
//                 ;
//             }
//             s.insert(head);
//             head = head->next;
//         }
//         return false;
//     }
// };

int main()
{
    Solution sol;
    return 0;
}