# include <iostream>    
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        Node *cur = head;
        while (cur)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        while (cur)
        {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        Node *newHead = head->next;
        Node *newCur = newHead;
        while (cur)
        {
            cur->next = newCur->next;
            cur = cur->next;
            if (cur)
            {
                newCur->next = cur->next;
                newCur = newCur->next;
            }
        }
        return newHead;
    }
};