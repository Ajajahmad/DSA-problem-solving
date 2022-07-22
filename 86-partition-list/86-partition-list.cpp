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
    ListNode* partition(ListNode* head, int x) {
        ListNode* nu= new ListNode(0);
        nu->next = head;
        ListNode* h=NULL, *l=nu;
        ListNode *p=NULL, *pre=NULL;
        p=head;
        int count=0;
        while(p!=NULL)
        {
            if(p->val >= x)
            {
                if(count==0)
                {
                     h = p;
                    count++;
                }
                pre = p;
                p=p->next;
            }
            else
            {
                if(count==0)
                {
                    l ->next = p;
                    l=p;
                    pre = p;
                    p=p->next;
                }
                else
                {
                    l->next = p;
                    pre->next = p->next;
                    p->next = h;
                    p = pre->next;
                    l=l->next;
                }
                
            }
        }
        return nu->next;
    }
};