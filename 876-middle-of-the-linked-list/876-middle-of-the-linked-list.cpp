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
    ListNode* middleNode(ListNode* head) {
        ListNode *p;
        p=head;
        int count=0,i=0;
        while(p!=0)
        {
            count++;
            p=p->next;
        }
        count=(count/2)+1;
       p=head;
      
        for(i=1;i<count;i++)
        {
           
            p=p->next;
        }
        return p;
    }
};