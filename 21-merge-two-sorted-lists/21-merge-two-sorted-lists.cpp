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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(!l1 && !l2)
            return l1;
       else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        else if(!l1 && !l2)
            return l1;
        ListNode *res,*ans ;
        if(l1->val<l2->val)
        {
            res=l1;
            l1=l1->next;
        }
        else
        {
            res=l2;
            l2=l2->next;
        }
        ans= res;
        ListNode *p=l1,*q=l2;
        while(p!=NULL && q!=NULL)
        {
            if(p->val < q->val)
            {
                ans->next=p;
                p=p->next;
            }
            else
            {
                ans->next= q;
                q=q->next;
            }
            ans=ans->next;
        }
        while(p!=NULL)
        {
            ans->next=p;
            p=p->next;
            ans=ans->next;
        }
        while(q!=NULL)
        {
            ans->next= q;
            q=q->next;
            ans=ans->next;
        }
        
        return res;
    }
};