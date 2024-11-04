# include <iostream>

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
private:
    ListNode *sortListSupport(ListNode *head,int size){
        if (size <= 1)
        {
            return head;
        }
        ListNode *left = head;
        ListNode *right = head;
        for (int i = 0; i < size / 2 - 1; i++)
        {
            right = right->next;
        }
        ListNode *temp2 = right;
        right = right->next;
        temp2->next = nullptr;
        left = sortListSupport(left, size / 2);
        right = sortListSupport(right, size - size / 2);
        ListNode *result = nullptr;
        ListNode *temp3 = nullptr;
        while (left && right)
        {
            if (left->val < right->val)
            {
                if (!result)
                {
                    result = left;
                    temp3 = result;
                }
                else
                {
                    temp3->next = left;
                    temp3 = temp3->next;
                }
                left = left->next;
            }
            else
            {
                if (!result)
                {
                    result = right;
                    temp3 = result;
                }
                else
                {
                    temp3->next = right;
                    temp3 = temp3->next;
                }
                right = right->next;
            }
        }
        while (left)
        {
            temp3->next = left;
            temp3 = temp3->next;
            left = left->next;
        }
        while (right)
        {
            temp3->next = right;
            temp3 = temp3->next;
            right = right->next;
        }
        return result;
    }
public:
    ListNode *sortList(ListNode *head)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }
        if (size <= 1)
        {
            return head;
        }
        return sortListSupport(head, size);
    }
};