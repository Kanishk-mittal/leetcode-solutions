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
private:
    void reverse(ListNode *&head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

public:
    int pairSum(ListNode *head)
    {
        int n = 0;
        ListNode *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        ListNode *first = head;
        ListNode *second = head;
        for (int i = 0; i < n / 2; i++)
        {
            second = second->next;
        }
        reverse(second);
        int maxSum = 0;
        while (second)
        {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return maxSum;
    }
};

int main()
{
    Solution sol;
    return 0;
}