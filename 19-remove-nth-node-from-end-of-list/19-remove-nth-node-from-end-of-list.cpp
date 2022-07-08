/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1)
        {
            head=NULL;
            return head;
        }
        ListNode *p=head,*q=head;
        int count=0;
        while(p!=NULL)
        {
            p=p->next;
            count++;
        }
        if(count==n)
        {
            p=head;
            head=p->next;
            delete(p);
            return head;
        }

        count = count-n+1;
        p=head;
        for(int i=0;i<count-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        return head;
    }
};