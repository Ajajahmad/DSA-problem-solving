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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *a=NULL, *b=head;
        int count = 0;
        while(b!=NULL)
        {
            if(b->next && b->next->val == b->val)
            {
                while(b->next && b->next->val == b->val)
                    b=b->next;
                b = b->next;
                if(b==NULL)
                {
                    if(count==0) return b;
                    else
                    {
                        a->next = b;
                        
                    }
                }
            }
            else 
            {
                if(count==0)
                {
                    head = b;
                    a=b;
                    count++;
                }

                else
                {
                    a->next = b;
                    a= a->next;
                }
                
                b = b->next;
            }
            
        }
        return head;
        
    }
};