#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos=1; // the current index
        int firstPos=-1; //position of first critical point
        int lastPos=-1; // position of last seen point 
        vector<int> result = {-1,-1};
        ListNode* curr = head;
        while (curr->next->next!=nullptr)
        {
            if(
                (curr->next->val > curr->val  && curr->next->val > curr->next->next->val) ||
                (curr->next->val < curr->val  && curr->next->val < curr->next->next->val)
            ){
                if (firstPos == -1)
                {
                    result={-1,-1};
                    firstPos=pos;
                    lastPos=pos;
                }else{
                    if (result[0]==-1 || result[0]>(pos-lastPos))
                    {
                        result[0]=pos-lastPos;
                    }
                    result[1]=pos-firstPos;
                    lastPos=pos;
                }
            }
            pos++;
            curr=curr->next;
        }
        return result;
    }
};

auto init = []() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
return 'c';
}();