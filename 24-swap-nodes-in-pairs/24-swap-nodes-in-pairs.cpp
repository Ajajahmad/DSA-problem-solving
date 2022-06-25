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
    ListNode* swapPairs(ListNode* head) {\
         if( !head) return NULL;
        if(!head->next ) return head;
       
        ListNode *p=head , *q=head->next , *r =new ListNode(0);
        int cnt =0;
        while(p && q){
            p->next = q->next;
            q->next = p;
            r ->next = q;
            if(cnt==0) head = q;
            cnt++;
            r = p;
            p = p->next;
            if(p)
                q = p->next;
        }
        return head;
    }
};