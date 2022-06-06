/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp;
        int l1=0,l2=0;
        temp = headA;
        while(temp!=NULL)
        {
            l1++;
            temp= temp->next;
        }
        temp = headB;
        while(temp!=NULL)
        {
            l2++;
            temp = temp->next;
            
        }
        if(l2>l1)
        {
            int count = l2-l1;
            while(count--)
            {
                headB = headB->next;
            }
        }
        else
        {
            int count= l1-l2;
            while(count--)
            {
                headA = headA->next;
            }
        }
        while(headA!=NULL && headB!=NULL)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA= headA->next;
            headB= headB->next;
        }
        return NULL;
    }
};