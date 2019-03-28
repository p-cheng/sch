#include<iostream>
struct ListNode {
    int val;
    ListNode *next;

};


ListNode *reverselinklist(ListNode *head)
{
        if(head == NULL)
            return NULL;
        ListNode *per,*p,*pnext;
        per = head;
        p = per->next;
        while(p)
        {
            pnext = p->next;
            p->next = per;
            per = p;
            p = pnext;
        }
        head->next = NULL;
        per = head;
        return head;
}

